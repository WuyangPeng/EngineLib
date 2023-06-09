// -*- C++ -*-
#include "ace/config-all.h"    /* Need ACE_TRACE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE int
ACE_OS::last_error ()
{
  // ACE_OS_TRACE ("ACE_OS::last_error");

#if defined (ACE_WIN32)
  // ACE_OS::last_error() prefers errnor since started out as a way to
  // avoid directly accessing errno in ACE code - particularly the ACE
  // C++ socket wrapper facades.  On Windows, some things that would
  // use errno on UNIX require ::GetLastError(), so this method tries
  // to shield the rest of ACE from having to know about this.
  int const lerror = ::GetLastError ();
  int const lerrno = errno;
  return lerrno == 0 ? lerror : lerrno;
#else
  return errno;
#endif /* ACE_WIN32 */
}

ACE_INLINE void
ACE_OS::last_error (int error)
{
  ACE_OS_TRACE ("ACE_OS::last_error");
#if defined (ACE_WIN32)
  ::SetLastError (error);
#endif /* ACE_WIN32 */
  errno = error;
}

ACE_INLINE int
ACE_OS::set_errno_to_last_error ()
{
# if defined (ACE_WIN32)
  return errno = ::GetLastError ();
#else
  return errno;
# endif /* defined(ACE_WIN32) */
}

ACE_INLINE int
ACE_OS::set_errno_to_wsa_last_error ()
{
# if defined (ACE_WIN32)
  return errno = ::WSAGetLastError ();
#else
  return errno;
# endif /* defined(ACE_WIN32) */
}

ACE_END_VERSIONED_NAMESPACE_DECL
