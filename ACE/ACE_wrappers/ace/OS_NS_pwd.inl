// -*- C++ -*-
#include "ace/OS_NS_errno.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Accessors to PWD file.

ACE_INLINE void
ACE_OS::endpwent ()
{
#if !defined (ACE_LACKS_PWD_FUNCTIONS)
  ::endpwent ();
#endif /* ! ACE_LACKS_PWD_FUNCTIONS */
}

ACE_INLINE struct passwd *
ACE_OS::getpwent ()
{
#if !defined (ACE_LACKS_PWD_FUNCTIONS)
  return ::getpwent ();
#else
  ACE_NOTSUP_RETURN (0);
#endif /* ! ACE_LACKS_PWD_FUNCTIONS */
}

ACE_INLINE struct passwd *
ACE_OS::getpwnam (const char *name)
{
#if !defined (ACE_LACKS_PWD_FUNCTIONS)
  return ::getpwnam (name);
# else
  ACE_UNUSED_ARG (name);
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_LACKS_PWD_FUNCTIONS */
}

ACE_INLINE int
ACE_OS::getpwnam_r (const char *name,
                    struct passwd *pwd,
                    char *buffer,
                    size_t bufsize,
                    struct passwd **result)
{
#if defined (ACE_LACKS_PWD_FUNCTIONS)
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (pwd);
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (bufsize);
  ACE_UNUSED_ARG (result);
  ACE_NOTSUP_RETURN (0);
#else
  return ::getpwnam_r (name, pwd, buffer, bufsize, result);
#endif /* ACE_LACKS_PWD_FUNCTIONS */
}

ACE_INLINE void
ACE_OS::setpwent ()
{
#if !defined (ACE_LACKS_PWD_FUNCTIONS)
  ::setpwent ();
#endif /* ! ACE_LACKS_PWD_FUNCTIONS */
}

ACE_END_VERSIONED_NAMESPACE_DECL
