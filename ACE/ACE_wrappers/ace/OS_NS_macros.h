// -*- C++ -*-

//=============================================================================
/**
 *  @file   OS_NS_macros.h
 *
 *  @author Douglas C. Schmidt <d.schmidt@vanderbilt.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 */
//=============================================================================

#ifndef ACE_OS_NS_MACROS_H
# define ACE_OS_NS_MACROS_H

# include /**/ "ace/pre.h"

# include "ace/config-all.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_WIN32)
# define ACE_SOCKCALL_RETURN(OP,TYPE,FAILVALUE) \
  do { TYPE ace_result_ = (TYPE) OP; \
      if (ace_result_ == FAILVALUE) { int ___ = ::WSAGetLastError (); errno = ___; return (TYPE) FAILVALUE; } else return ace_result_; \
  } while (0)
# define ACE_SOCKCALL(OP,TYPE,FAILVALUE,RESULT) \
  do { RESULT = (TYPE) OP; \
      if (RESULT == FAILVALUE) { int ___ = ::WSAGetLastError (); errno = ___; RESULT = FAILVALUE; } \
  } while (0)
#else
# define ACE_SOCKCALL_RETURN(OP,TYPE,FAILVALUE) ACE_OSCALL_RETURN(OP,TYPE)
# define ACE_SOCKCALL(OP,TYPE,FAILVALUE,RESULT) ACE_OSCALL(OP,TYPE,RESULT)
#endif /* ACE_WIN32 */

#if !defined (ACE_WIN32)

// Adapt the weird threading and synchronization routines (which
// return errno rather than -1) so that they return -1 and set errno.
// This is more consistent with the rest of ACE_OS and enables us to
// use the ACE_OSCALL* macros.
# if defined (ACE_VXWORKS)
#   define ACE_ADAPT_RETVAL(OP,RESULT) ((RESULT = (OP)) != OK ? (errno = RESULT, -1) : 0)
# else
#   define ACE_ADAPT_RETVAL(OP,RESULT) ((RESULT = (OP)) != 0 ? (errno = RESULT, -1) : 0)
# endif /* ACE_VXWORKS */

#else /* ACE_WIN32 */

// Adapt the Win32 System Calls (which return BOOLEAN values of TRUE
// and FALSE) into int values expected by the ACE_OSCALL macros.
# define ACE_ADAPT_RETVAL(OP,RESULT) ((RESULT = (OP)) == FALSE ? -1 : 0)

// Perform a mapping of Win32 error numbers into POSIX errnos.
# define ACE_FAIL_RETURN(RESULT) do { \
  switch (ACE_OS::set_errno_to_last_error ()) { \
  case ERROR_NOT_ENOUGH_MEMORY: errno = ENOMEM; break; \
  case ERROR_FILE_EXISTS:       errno = EEXIST; break; \
  case ERROR_SHARING_VIOLATION: errno = EACCES; break; \
  case ERROR_PATH_NOT_FOUND:    errno = ENOENT; break; \
  } \
  return RESULT; } while (0)

#endif /* !ACE_WIN32 */

// Helper functions to split large integers into smaller high-order
// and low-order parts, and reconstitute them again.  These are
// required primarily for supporting _FILE_OFFSET_BITS==64 on windows.
#if defined(ACE_WIN32)
#  if defined(_FILE_OFFSET_BITS) && (_FILE_OFFSET_BITS==64)
#    include "ace/Basic_Types.h"

#    define ACE_LOW_PART(X) static_cast<DWORD>(X)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
LONG
inline ACE_High_Part (LONGLONG value)
{
  LARGE_INTEGER new_value;
  new_value.QuadPart = value;
  return new_value.HighPart;
}
#    define ACE_HIGH_PART(X) ACE_High_Part(X)

LONGLONG
inline ACE_Combine_Parts (LONG high, DWORD low)
{
  LARGE_INTEGER value;
  value.LowPart = low;    // DWORD
  value.HighPart = high;  // LONG
  return value.QuadPart;
}
ACE_END_VERSIONED_NAMESPACE_DECL

#    define ACE_COMBINE_PARTS(X,Y) ACE_Combine_Parts(X,Y)
#  else  /* _FILE_OFFSET_BITS==64 */
#    define ACE_LOW_PART(X) X
#    define ACE_HIGH_PART(X) 0
#    define ACE_COMBINE_PARTS(X,Y) X
#  endif /* _FILE_OFFSET_BITS==64 */
#endif /* ACE_WIN32 */

// 64-bit quad-word definitions.
#if defined (ACE_WIN32)
#  if defined (_FILE_OFFSET_BITS) && (_FILE_OFFSET_BITS == 64)
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
typedef unsigned __int64 ACE_QWORD;
inline ACE_QWORD ACE_Make_QWORD (DWORD lo, DWORD hi) { return ACE_QWORD (lo) | (ACE_QWORD (hi) << 32); }
inline DWORD ACE_Low_DWORD  (ACE_QWORD q) { return (DWORD) q; }
inline DWORD ACE_High_DWORD (ACE_QWORD q) { return (DWORD) (q >> 32); }
ACE_END_VERSIONED_NAMESPACE_DECL
#  endif /* _FILE_OFFSET_BITS==64 */
#endif /* ACE_WIN32 */

# include /**/ "ace/post.h"

#endif /* ACE_OS_NS_MACROS_H */
