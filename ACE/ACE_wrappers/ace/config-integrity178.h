// -*- C++ -*-

#ifndef ACE_CONFIG_INTEGRITY178_H
#define ACE_CONFIG_INTEGRITY178_H

/*
 * This config.h file is for version 5.0.0 of the
 * INTEGRITY-178B RTOS from Green Hills Software
 * http://www.ghs.com/products/rtos/integrity.html
 */

#include "config-integrity-common.h"

// The macro ACE_INTEGRITY178B is used in places where the ACE_INTEGRITY macro
// is not sufficient due to differences between this version of INTEGRITY-178 and the
// INTEGRITY version that was used by this version of ACE. For example, INTEGRITY-178
// does not have AllocateNullConsoleDescriptor function (see OS_NS_fcntl.cpp).
// NOTE: if ACE_INTEGRITY178B is defined, then ACE_INTEGRITY is also defined.
#define ACE_INTEGRITY178B

// Exclude unavailable functions in libraries such as libposix_178b_be.a or file systems libraries.
#if defined ACE_LACKS_POSIX
# define ACE_LACKS_FSTAT
# define ACE_LACKS_LSTAT
# define ACE_LACKS_STAT
# define ACE_LACKS_UMASK
# define ACE_LACKS_GETTIMEOFDAY
# define ACE_LACKS_ALARM
# define ACE_LACKS_DUP
# define ACE_LACKS_DUP2
# define ACE_LACKS_FTRUNCATE
# define ACE_LACKS_GETHOSTNAME
# define ACE_LACKS_SLEEP
# define ACE_LACKS_SELECT
# define ACE_LACKS_READV
# define ACE_LACKS_WRITEV
# define ACE_LACKS_KILL
# define ACE_LACKS_SIGEMPTYSET
# define ACE_LACKS_SIGFILLSET
# define ACE_LACKS_SIGISMEMBER
# define ACE_LACKS_SIGADDSET
# define ACE_LACKS_SIGDELSET
# define ACE_LACKS_SIGPROCMASK
# define ACE_LACKS_TIME
# define ACE_LACKS_MMAP
# define ACE_LACKS_SETEGID
# define ACE_LACKS_SETUID
# define ACE_LACKS_SETEUID
# define ACE_LACKS_SETGID
# define ACE_LACKS_GETEUID
# define ACE_LACKS_GETUID
# define ACE_LACKS_GETEGID
# define ACE_LACKS_GETGID
# define ACE_LACKS_TEMPNAM /* believe it or not, this is ANSI C */
# define ACE_LACKS_STRPTIME
# define ACE_LACKS_SYSTEM
# define ACE_LACKS_WAIT
# define ACE_LACKS_WAITPID
# define ACE_LACKS_EXEC
# define ACE_LACKS_FORK
# define ACE_LACKS_MKFIFO
# define ACE_LACKS_MKTEMP
# define ACE_LACKS_MKSTEMP
# define ACE_LACKS_MPROTECT
# define ACE_LACKS_SEEKDIR
# define ACE_LACKS_MSYNC
# define ACE_LACKS_UNAME
# define ACE_LACKS_ISATTY
# define ACE_LACKS_STRCASECMP
# define ACE_LACKS_TRUNCATE
# define ACE_LACKS_GETOPT
# define ACE_LACKS_SIGWAIT
#endif

// Support turning off network utility functions from GHNet-178's libnet.a.
// However, socket functions from GHNet-178's libsocket.a must be available.
#if defined ACE_NO_GHNET178_LIBNET
/***** Network utility functions *****/
# define ACE_LACKS_GETADDRINFO
# define ACE_LACKS_GAI_STRERROR
# define ACE_LACKS_GETNAMEINFO
# define ACE_LACKS_GETSERVBYNAME
# define ACE_LACKS_IF_NAMEINDEX
# define ACE_LACKS_IF_NAMETOINDEX
# define ACE_LACKS_GETHOSTBYADDR
# define ACE_LACKS_GETHOSTBYNAME
# define ACE_LACKS_GETPROTOBYNAME
# define ACE_LACKS_GETPROTOBYNUMBER
# define ACE_LACKS_GETHOSTBYADDR_R
# define ACE_LACKS_GETHOSTBYNAME_R
# define ACE_LACKS_GETPROTOBYNAME_R
# define ACE_LACKS_GETPROTOBYNUMBER_R
# define ACE_LACKS_INET_ADDR
# define ACE_LACKS_INET_NTOA
# define ACE_LACKS_INET_ATON
# define ACE_LACKS_INET_NTOP
# define ACE_LACKS_INET_PTON

/***** Socket functions *****/
# define ACE_LACKS_FCNTL
# define ACE_LACKS_IOCTL
# define ACE_LACKS_RECVMSG
# define ACE_LACKS_SENDMSG
# define ACE_LACKS_SHUTDOWN
# define ACE_LACKS_SOCKETPAIR
#endif

/****** Posix Defines *****/
#define ACE_LACKS_DLFCN_H
#define ACE_LACKS_REGEX_H

/****** C++17 Defines *****/
#define ACE_LACKS_STD_WSTRING
#define ACE_LACKS_STD_STRING_VIEW
#define ACE_FALLTHROUGH

// INTEGRITY has the concept of thread-specific storage in its native API.
// It's mentioned as Task-specific data in its document.
// INTEGRITY-178B does not seem to have thread-specific storage. TSS is just
// mentioned in some places in the manuals but there are no APIs.
// We, therefore, use ACE's TSS emulation.
#define ACE_HAS_TSS_EMULATION

#endif /* ACE_CONFIG_INTEGRITY178_H */
