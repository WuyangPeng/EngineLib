// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_time.h
 *
 *  time types
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_TIME_H
#define ACE_OS_INCLUDE_OS_TIME_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// @todo should we include anything from signal.h?
#include "ace/os_include/sys/os_types.h"

// To get the proper select() signature, this is required for maybe other platforms
// that offer both int and fdset forms of select().
#if !defined (ACE_LACKS_SYS_TIME_H)
#  include /**/ <sys/time.h>
#endif /* !ACE_LACKS_SYS_TIME_H */

#include /**/ <time.h>

#if defined (ACE_USES_STD_NAMESPACE_FOR_STDC_LIB) && \
            (ACE_USES_STD_NAMESPACE_FOR_STDC_LIB != 0)
using std::tm;
# if defined (ACE_WIN32)
using std::_timezone;
# else
using std::timezone;
# endif /* ACE_WIN32 */
using std::difftime;
#endif /* ACE_USES_STD_NAMESPACE_FOR_STDC_LIB */

# if !defined (ACE_HAS_POSIX_TIME)
// Definition per POSIX.
typedef struct timespec
{
  /// Seconds
  time_t tv_sec;
  /// Nanoseconds
  long tv_nsec;
} timespec_t;
# endif /* !ACE_HAS_POSIX_TIME */

# if defined(ACE_LACKS_TIMESPEC_T)
typedef struct timespec timespec_t;
# endif /* ACE_LACKS_TIMESPEC_T */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

// There are a lot of threads-related macro definitions in the config files.
// They came in at different times and from different places and platform
// requirements as threads evolved.  They are probably not all needed - some
// overlap or are otherwise confused.  This is an attempt to start
// straightening them out.
#if defined (ACE_HAS_PTHREADS)    /* POSIX.1c threads (pthreads) */
   // ... and 2-parameter asctime_r and ctime_r
#  if !defined (ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R) && !defined (ACE_VXWORKS)
#    define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R
#  endif
#endif /* ACE_HAS_PTHREADS */

#if defined (ACE_LACKS_CONST_TIMESPEC_PTR)
typedef struct timespec * ACE_TIMESPEC_PTR;
#else
typedef const struct timespec * ACE_TIMESPEC_PTR;
#endif /* ACE_LACKS_CONST_TIMESPEC_PTR */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_TIME_H */
