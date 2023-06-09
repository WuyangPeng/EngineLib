/* -*- C -*- */
/* The following configuration file is designed to work for RTEMS
   platforms using GNU C.
*/

#ifndef ACE_CONFIG_POSIX_NONETWORKING_H
#define ACE_CONFIG_POSIX_NONETWORKING_H

// Missing header files
# define ACE_LACKS_SYS_UIO_H
# define ACE_LACKS_SYS_SOCKET_H
# define ACE_LACKS_NETINET_IN_H
# define ACE_LACKS_NETDB_H
# define ACE_LACKS_ARPA_INET_H
# define ACE_LACKS_SYS_SELECT_H
# define ACE_LACKS_NET_IF_H
# define ACE_LACKS_SYSLOG_H
# define ACE_LACKS_SYS_UN_H
# define ACE_LACKS_SYS_SYSCTL_H
# define ACE_LACKS_NETINET_TCP_H

// Missing types
# define ACE_LACKS_IOVEC
# define ACE_LACKS_IN_ADDR
# define ACE_LACKS_SOCKADDR_IN
# define ACE_LACKS_SOCKADDR_UN
# define ACE_LACKS_HOSTENT
# define ACE_LACKS_SOCKADDR
# define ACE_LACKS_IP_MREQ
# define ACE_LACKS_PROTOENT
# define ACE_LACKS_SERVENT
# define ACE_LACKS_IFREQ
# define ACE_LACKS_IFCONF
# define ACE_LACKS_LINGER

// Missing methods
# define ACE_LACKS_GETHOSTBYADDR
# define ACE_LACKS_GETHOSTBYNAME
# define ACE_LACKS_GETIPNODEBYADDR
# define ACE_LACKS_LISTEN
# define ACE_LACKS_BIND
# define ACE_LACKS_NTOHL
# define ACE_LACKS_HTONL
# define ACE_LACKS_HTONS
# define ACE_LACKS_NTOHS
# define ACE_LACKS_SELECT
# define ACE_LACKS_SOCKET
# define ACE_LACKS_SHUTDOWN
# define ACE_LACKS_SETSOCKOPT
# define ACE_LACKS_INET_ATON
# define ACE_LACKS_INET_ADDR
# define ACE_LACKS_INET_NTOA
# define ACE_LACKS_GET_BCAST_ADDR
# define ACE_LACKS_GETHOSTENT
# define ACE_LACKS_GETSERVBYNAME
# define ACE_LACKS_ACCEPT
# define ACE_LACKS_CONNECT
# define ACE_LACKS_GETPEERNAME
# define ACE_LACKS_GETSOCKNAME
# define ACE_LACKS_GETSOCKOPT
# define ACE_LACKS_RECV
# define ACE_LACKS_SEND
# define ACE_LACKS_SENDTO
# define ACE_LACKS_RECVFROM
# define ACE_LACKS_RECVMSG
# define ACE_LACKS_SENDMSG
# define ACE_LACKS_GETHOSTBYADDR_R
# define ACE_LACKS_GETPROTOBYNAME
# define ACE_LACKS_GETPROTOBYNUMBER
# define ACE_LACKS_GETSERVBYNAME
# define ACE_LACKS_READV
# define ACE_LACKS_WRITEV
# define ACE_LACKS_SOCKETPAIR
# undef ACE_HAS_MSG

// Missing OS features
# define ACE_LACKS_UNIX_SYSLOG
# define ACE_LACKS_TCP_NODELAY

// Missing ACE features
# define ACE_DISABLE_NOTIFY_PIPE_DEFAULT 1

#endif /* ACE_CONFIG_POSIX_NONETWORKING_H */
