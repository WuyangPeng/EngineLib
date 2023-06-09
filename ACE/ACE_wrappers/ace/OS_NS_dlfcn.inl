// -*- C++ -*-
#include "ace/OS_NS_macros.h"
#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_fcntl.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_unistd.h"
#include "ace/Default_Constants.h"
#include "ace/os_include/os_fcntl.h"
#include "ace/os_include/os_string.h"

#if defined (ACE_USES_ASM_SYMBOL_IN_DLSYM)
#  include "ace/OS_Memory.h"
#  include "ace/OS_NS_string.h"
#endif /* ACE_USES_ASM_SYMBOL_IN_DLSYM */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE int
ACE_OS::dlclose (ACE_SHLIB_HANDLE handle)
{
  ACE_OS_TRACE ("ACE_OS::dlclose");
#if defined (ACE_LACKS_DLCLOSE)
  ACE_UNUSED_ARG (handle);
  return 0;
#elif defined (ACE_HAS_SVR4_DYNAMIC_LINKING)

# if !defined (ACE_HAS_AUTOMATIC_INIT_FINI)
  // SunOS4 does not automatically call _fini()!
  void *ptr;

  ACE_OSCALL (::dlsym (handle, ACE_TEXT ("_fini")), void *, ptr);

  if (ptr != 0)
    (*((int (*)(void)) ptr)) (); // Call _fini hook explicitly.
# endif /* ACE_HAS_AUTOMATIC_INIT_FINI */
  return ::dlclose (handle);
#elif defined (ACE_WIN32)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::FreeLibrary (handle), ace_result_), int, -1);
#else
  ACE_UNUSED_ARG (handle);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_SVR4_DYNAMIC_LINKING */
}

ACE_INLINE ACE_TCHAR *
ACE_OS::dlerror ()
{
  ACE_OS_TRACE ("ACE_OS::dlerror");
# if defined (ACE_HAS_SVR4_DYNAMIC_LINKING)
  const char *err = 0;
  ACE_OSCALL (::dlerror (), const char *, err);
  if (err == 0)
    return 0;
#   if defined (ACE_USES_WCHAR)
  const size_t BufLen = 256;
  static wchar_t buf[BufLen];
  ACE_OS::strncpy (buf, ACE_TEXT_CHAR_TO_TCHAR (err), BufLen);
  return buf;
#   else
  return const_cast <char *> (err);
#   endif /* ACE_USES_WCHAR */
# elif defined (ACE_VXWORKS)
  //FUZZ: disable check_for_lack_ACE_OS
  return ::strerror(errno);
  //FUZZ: enable check_for_lack_ACE_OS
# elif defined (ACE_WIN32)
  static ACE_TCHAR buf[128];
  ACE_TEXT_FormatMessage (FORMAT_MESSAGE_FROM_SYSTEM,
                          0,
                          ::GetLastError (),
                          0,
                          buf,
                          sizeof buf / sizeof buf[0],
                          0);
  return buf;
# else
  ACE_NOTSUP_RETURN (0);
# endif /* ACE_HAS_SVR4_DYNAMIC_LINKING */
}

ACE_INLINE ACE_SHLIB_HANDLE
ACE_OS::dlopen (const ACE_TCHAR *fname,
                int mode)
{
  ACE_OS_TRACE ("ACE_OS::dlopen");

# if defined (ACE_HAS_SVR4_DYNAMIC_LINKING)
  void *handle;
  ACE_OSCALL (::dlopen (ACE_TEXT_ALWAYS_CHAR (fname), mode), void *, handle);
#   if !defined (ACE_HAS_AUTOMATIC_INIT_FINI)
  if (handle != 0)
    {
      void *ptr;
      // Some systems (e.g., SunOS4) do not automatically call _init(), so
      // we'll have to call it manually.

      ACE_OSCALL (::dlsym (handle, ACE_TEXT ("_init")), void *, ptr);

      if (ptr != 0 && (*((int (*)(void)) ptr)) () == -1) // Call _init hook explicitly.
        {
          // Close down the handle to prevent leaks.
          ::dlclose (handle);
          return 0;
        }
    }
#   endif /* ACE_HAS_AUTOMATIC_INIT_FINI */
  return handle;
# elif defined (ACE_WIN32)
  ACE_UNUSED_ARG (mode);

  ACE_WIN32CALL_RETURN (ACE_TEXT_LoadLibrary (fname), ACE_SHLIB_HANDLE, 0);
# elif defined (ACE_VXWORKS) && !defined (__RTP__)
  ACE_UNUSED_ARG (mode);
  MODULE* handle = 0;
  // Open readonly
  ACE_HANDLE filehandle = ACE_OS::open (fname,
                                        O_RDONLY,
                                        ACE_DEFAULT_FILE_PERMS);

  if (filehandle != ACE_INVALID_HANDLE)
    {
      ACE_OS::last_error(0);
      ACE_OSCALL ( ::loadModule (filehandle, LOAD_GLOBAL_SYMBOLS|LOAD_COMMON_MATCH_ALL ), MODULE *, handle);
      int loaderror = ACE_OS::last_error();
      ACE_OS::close (filehandle);

      if ( (loaderror != 0) && (handle != 0) )
        {
          // ouch something went wrong most likely unresolved externals
          if (handle)
            ::unldByModuleId ( handle, 0 );
          handle = 0;
        }
    }
  else
    {
      // couldn't open file
      handle = 0;
    }
  return handle;
# else
  ACE_UNUSED_ARG (fname);
  ACE_UNUSED_ARG (mode);
  ACE_NOTSUP_RETURN (0);
# endif /* ACE_HAS_SVR4_DYNAMIC_LINKING */
}

ACE_INLINE void *
ACE_OS::dlsym (ACE_SHLIB_HANDLE handle,
               const ACE_TCHAR *sname)
{
  ACE_OS_TRACE ("ACE_OS::dlsym");

  // Check if the handle is valid before making any calls using it.
  if (handle == ACE_SHLIB_INVALID_HANDLE)
    return nullptr;

  // Get the correct OS type.
#if defined (ACE_USES_WCHAR)
  ACE_Wide_To_Ascii w_sname (sname);
  char *symbolname = w_sname.char_rep ();
#elif defined (ACE_VXWORKS)
  char *symbolname = const_cast<char *> (sname);
#else
  const char *symbolname = sname;
#endif /* ACE_USES_WCHAR */

# if defined (ACE_HAS_SVR4_DYNAMIC_LINKING)

#   if defined (ACE_USES_ASM_SYMBOL_IN_DLSYM)
  int const l = ACE_OS::strlen (symbolname) + 2;
  char *asm_symbolname {};
  ACE_NEW_RETURN (asm_symbolname, char[l], 0);
  ACE_OS::strcpy (asm_symbolname, "_") ;
  ACE_OS::strcpy (asm_symbolname + 1, symbolname) ;
  void *ace_result;
  ACE_OSCALL (::dlsym (handle, asm_symbolname), void *, ace_result);
  delete [] asm_symbolname;
  return ace_result;
#   else
  return ::dlsym (handle, symbolname);
#   endif /* ACE_USES_ASM_SYMBOL_IN_DLSYM */
# elif defined (ACE_WIN32)
  ACE_WIN32CALL_RETURN (::GetProcAddress (handle, symbolname), void *, 0);
# elif defined (ACE_VXWORKS) && !defined (__RTP__)
  // For now we use the VxWorks global symbol table
  // which resolves the most recently loaded symbols, which resolve
  // mostly what we want..
  ACE_UNUSED_ARG (handle);
#if (ACE_VXWORKS < 0x690)
  SYM_TYPE symtype;
  char *value = 0;
  STATUS status;
  ACE_OSCALL (::symFindByName(sysSymTbl, symbolname, &value, &symtype), int, status);

  return status == OK ? reinterpret_cast <void*>(value) : nullptr;
#else
  STATUS status;

  SYMBOL_DESC symbolDesc;     /* symFind() descriptor */
  ACE_OS::memset (&symbolDesc, 0, sizeof (SYMBOL_DESC));
  symbolDesc.mask = SYM_FIND_BY_NAME;
  symbolDesc.name = symbolname;

  ACE_OSCALL (::symFind(sysSymTbl, &symbolDesc), int, status);

  return status == OK ? reinterpret_cast <void*>(symbolDesc.value) : nullptr;
#endif /* (ACE_VXWORKS < 0x690) */

# else
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (symbolname);
  ACE_NOTSUP_RETURN (nullptr);
# endif /* ACE_HAS_SVR4_DYNAMIC_LINKING */
}

ACE_END_VERSIONED_NAMESPACE_DECL
