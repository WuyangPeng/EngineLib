// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_socket.h
 *
 *  main sockets header
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_SYS_OS_SOCKET_H
#define ACE_OS_INCLUDE_SYS_OS_SOCKET_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/os_uio.h"

#if !defined (ACE_LACKS_SYS_SOCKET_H)
#  include /**/ <sys/socket.h>
#endif /* !ACE_LACKS_SYS_SOCKET_H */

#if defined (ACE_USES_SOCKET_H)
#  include /**/ <socket.h>
#endif /* ACE_USES_SOCKET_H */

#if defined (ACE_USES_SOCKLIB_H)
#  include /**/ <sockLib.h>
#endif /* ACE_USES_SOCKLIB_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#if !defined (ACE_HAS_MSG)
   struct msghdr {};
#endif /* ACE_HAS_MSG */

#if defined (ACE_HAS_MSG) && defined (ACE_LACKS_MSG_ACCRIGHTS)
#  if !defined (msg_accrights)
#    undef msg_control
#    define msg_accrights msg_control
#  endif /* ! msg_accrights */

#  if !defined (msg_accrightslen)
#    undef msg_controllen
#    define msg_accrightslen msg_controllen
#  endif /* ! msg_accrightslen */
#endif /* ACE_HAS_MSG && ACE_LACKS_MSG_ACCRIGHTS */

# if defined (ACE_LACKS_SOCKADDR)
    struct sockaddr {
            u_char  sa_len;                 /* total length */
            u_char  sa_family;              /* address family */
            char    sa_data[14];            /* actually longer; address value */
    };
# endif /* ACE_LACKS_SOCKADDR */

# if defined (ACE_LACKS_LINGER)
    struct  linger {
          int     l_onoff;                /* option on/off */
          int     l_linger;               /* linger time */
    };
# endif /* ACE_LACKS_LINGER */

#if defined (ACE_LACKS_MSGHDR)
   struct msghdr
   {
     /// Optional address
     sockaddr *msg_name;

     /// Size of address
     int msg_namelen;

     /// Scatter/gather array
     iovec *msg_iov;

     /// # elements in msg_iov
     int msg_iovlen;

     /// Access rights sent/received
     caddr_t msg_accrights;

     int msg_accrightslen;

     /// Control messages, set msg_control to 0 if not using:
     void *msg_control;
     int msg_controllen;
   };

   typedef WSACMSGHDR cmsghdr;
#endif /* ACE_LACKS_MSGHDR */

   // Using msghdr::msg_control and msghdr::msg_controllen portably:
   // For a parameter of size n, reserve space for ACE_CMSG_SPACE(n) bytes.
   // This can be extended to the sum of ACE_CMSG_SPACE(n_i) for multiple
   // parameters.
   // Pass that buffer's address and length as msg_control/msg_controllen when
   // invoking sendmsg/recvmsg.  The buffer's address must be aligned to hold an
   // object of type cmsghdr at the beginning of the buffer.
   // If the send or recv succeeds, examine the
   // resulting cmsg structure using the following macros with signatures:
   // cmsghdr *ACE_CMSG_FIRSTHDR(msghdr *m)
   // cmsghdr *ACE_CMSG_NXTHDR(msghdr *m, cmsghdr *c)
   // unsigned char *ACE_CMSG_DATA(cmsghdr *c)

#ifdef ACE_WIN32
#  define ACE_CMSG_SPACE WSA_CMSG_SPACE
#  define ACE_CMSG_FIRSTHDR(msg)                                \
     (((unsigned) (msg)->msg_controllen >= sizeof (WSACMSGHDR)) \
      ? (LPWSACMSGHDR) (msg)->msg_control : (LPWSACMSGHDR) 0)
#  define ACE_CMSG_NXTHDR(msg, cmsg)                               \
      (((cmsg) == 0) ? ACE_CMSG_FIRSTHDR (msg)                     \
       : ((((PUCHAR) (cmsg) + WSA_CMSGHDR_ALIGN ((cmsg)->cmsg_len) \
            + sizeof (WSACMSGHDR)) > (PUCHAR) ((msg)->msg_control) \
           + (msg)->msg_controllen)                                \
          ? (LPWSACMSGHDR) 0                                       \
          : (LPWSACMSGHDR) ((PUCHAR) (cmsg)                        \
                           + WSA_CMSGHDR_ALIGN ((cmsg)->cmsg_len))))
#  define ACE_CMSG_DATA WSA_CMSG_DATA
#else
#  define ACE_CMSG_SPACE CMSG_SPACE
#  define ACE_CMSG_FIRSTHDR CMSG_FIRSTHDR
#  define ACE_CMSG_NXTHDR CMSG_NXTHDR
#  define ACE_CMSG_DATA CMSG_DATA
#endif

#if defined (ACE_HAS_4_4BSD_SENDMSG_RECVMSG)
   // Control message size to pass a file descriptor.
#  define ACE_BSD_CONTROL_MSG_LEN sizeof (struct cmsghdr) + sizeof (ACE_HANDLE)
#endif /* ACE_HAS_4_4BSD_SENDMSG_RECVMSG */

// Increase the range of "address families".  Please note that this
// must appear _after_ the include of sys/socket.h, for the AF_FILE
// definition on Linux/glibc2.
#if !defined (AF_ANY)
#  define AF_ANY (-1)
#endif /* AF_ANY */

#if !defined (AF_UNSPEC)
#  define AF_UNSPEC 0
#endif /* AF_UNSPEC */

#if !defined (AF_LOCAL)
#  define AF_LOCAL 1
#endif /* AF_LOCAL */

#if !defined (AF_UNIX)
#  define AF_UNIX AF_LOCAL
#endif /* AF_UNIX */

#if !defined (AF_INET)
#  define AF_INET 2
#endif /* AF_INET */

#if !defined (PF_INET)
#  define PF_INET AF_INET
#endif /* PF_INET */

#if !defined (PF_LOCAL)
#  define PF_LOCAL AF_LOCAL
#endif /* PF_LOCAL */

#if !defined (PF_UNIX)
#  define PF_UNIX PF_LOCAL
#endif /* PF_UNIX */

#if !defined (AF_MAX)
#  define AF_MAX 29
#endif /* AF_MAX */

#if !defined (PF_UNSPEC)
#  define PF_UNSPEC 0
#endif /* PF_UNSPEC */

#define AF_SPIPE (AF_MAX + 1)
#if !defined (AF_FILE)
#  define AF_FILE (AF_MAX + 2)
#endif /* ! AF_FILE */
#define AF_DEV (AF_MAX + 3)
#define AF_UPIPE (AF_SPIPE)

#if !defined (MSG_OOB)
#  define MSG_OOB 0x1
#endif /* MSG_OOB */

#if !defined (MSG_PEEK)
#  define MSG_PEEK 0x2
#endif /* MSG_PEEK */

#if !defined (SOCK_STREAM)
#  define SOCK_STREAM 1
#endif /* SOCK_STREAM */

#if !defined (SOCK_DGRAM)
#  define SOCK_DGRAM 2
#endif /* SOCK_DGRAM */

#if !defined (SOCK_SEQPACKET)
#  define SOCK_SEQPACKET 5
#endif /* SOCK_SEQPACKET */

#if !defined (SOL_SOCKET)
#  define SOL_SOCKET 0xffff
#endif /* SOL_SOCKET */

#if !defined (SO_REUSEADDR)
#  define SO_REUSEADDR 0x0004
#endif /* SO_REUSEADDR */

#if !defined (SO_LINGER)
#  define SO_LINGER 0x0080
#endif /* SO_LINGER */

#if !defined (SO_SNDBUF)
#  define SO_SNDBUF 0x1001
#endif /* SO_SNDBUF */

#if !defined (SO_RCVBUF)
#  define SO_RCVBUF 0x1002
#endif /* SO_RCVBUF */

#if !defined (SO_BROADCAST)
#  define SO_BROADCAST 0x0020
#endif /* SO_BROADCAST */

#if !defined (SO_ERROR)
#  define SO_ERROR 0x1007
#endif /* SO_ERROR */

#if !defined (SCM_RIGHTS)
#  define SCM_RIGHTS 0x01
#endif /* SCM_RIGHTS */

#if defined (ACE_HAS_IPV6)
#  if defined (ACE_USES_IPV4_IPV6_MIGRATION)
#    define ACE_ADDRESS_FAMILY_INET  AF_UNSPEC
#    define ACE_PROTOCOL_FAMILY_INET PF_UNSPEC
#  else
#    define ACE_ADDRESS_FAMILY_INET AF_INET6
#    define ACE_PROTOCOL_FAMILY_INET PF_INET6
#  endif /* ACE_USES_IPV4_IPV6_MIGRATION */
#else /* !ACE_HAS_IPV6 */
#  define ACE_ADDRESS_FAMILY_INET AF_INET
#  define ACE_PROTOCOL_FAMILY_INET PF_INET
#endif /* ACE_HAS_IPV6 */

#define ACE_HAS_SOCK_BUF_SIZE_MAX_VALUE SSIZE_MAX

#if !defined (ACE_SOCKET_LEN)
#if defined (ACE_HAS_SOCKLEN_T)
typedef socklen_t ACE_SOCKET_LEN;
#else
typedef int ACE_SOCKET_LEN;
#endif /* ACE_HAS_SOCKLEN_T */
#endif /* ACE_SOCKET_LEN */

#if defined (ACE_HAS_NETLINK)
#  include /**/ <asm/types.h>
#  include /**/ <linux/netlink.h>
#  define ACE_PROTOCOL_FAMILY_NETLINK AF_NETLINK
#endif

#if defined (ACE_HAS_LKSCTP)
extern "C"
{
#include /**/ <netinet/in.h>
#include /**/ <netinet/sctp.h>
}
#endif /* ACE_HAS_LKSCTP */

# if defined (ACE_LACKS_TIMEDWAIT_PROTOTYPES)

  ssize_t recv_timedwait (ACE_HANDLE handle,
                          char *buf,
                          int len,
                          int flags,
                          struct timespec *timeout);

  ssize_t recvmsg_timedwait (ACE_HANDLE handle,
                             struct msghdr *msg,
                             int flags,
                             struct timespec *timeout);

  ssize_t recvfrom_timedwait (ACE_HANDLE handle,
                              char *buf,
                              int len,
                              int flags,
                              struct sockaddr *addr,
                              int *addrlen,
                              struct timespec *timeout);

  ssize_t send_timedwait (ACE_HANDLE handle,
                          const char *buf,
                          int len,
                          int flags,
                          struct timespec *timeout);

  ssize_t sendmsg_timedwait (ACE_HANDLE handle,
                             const struct msghdr *msg,
                             int flags,
                             struct timespec *timeout);

  ssize_t sendto_timedwait (ACE_HANDLE handle,
                            const char *buf,
                            int len,
                            int flags,
                            const struct sockaddr *addr,
                            int addrlen,
                            struct timespec *timeout);

# endif /* ACE_LACKS_TIMEDWAIT_PROTOTYPES */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_SYS_OS_SOCKET_H */
