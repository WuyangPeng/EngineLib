// -*- C++ -*-

//=============================================================================
/**
 *  @file   OS_Errno.h
 *
 *  @author Doug Schmidt <d.schmidt@vanderbilt.edu>
 */
//=============================================================================

#ifndef ACE_OS_ERRNO_H
#define ACE_OS_ERRNO_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/OS_NS_errno.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Errno_Guard
 *
 * @brief Provides a wrapper to improve performance when thread-specific
 * errno must be saved and restored in a block of code.
 *
 * The typical use-case for this is the following:
 * int error = errno;
 * call_some_function_that_might_change_errno ();
 * errno = error;
 * This can be replaced with
 * {
 * ACE_Errno_Guard guard (errno);
 * call_some_function_that_might_change_errno ();
 * }
 * This implementation is more elegant and more efficient since it
 * avoids an unnecessary second access to thread-specific storage
 * by caching a pointer to the value of errno in TSS.
 */
class ACE_Export ACE_Errno_Guard
{
public:
  ///  Stash the value of @a error into @c error_ and initialize the
  ///  @c errno_ptr_ to the address of @a errno_ref.
  ACE_Errno_Guard (ACE_ERRNO_TYPE &errno_ref,
                   int error);

  ///  Initialize the @c errno_ptr_ to the address of @a errno_ref.
  ACE_Errno_Guard (ACE_ERRNO_TYPE &errno_ref);

  /// Reset the value of @c errno to <error>.
  ~ACE_Errno_Guard ();

  /// Assign @a erro> to error_.
  int operator= (int error);

  /// Compare @a error with error_ for equality.
  bool operator== (int error);

  /// Compare @a error with error_ for inequality.
  bool operator!= (int error);

private:
  ACE_Errno_Guard (const ACE_Errno_Guard &) = delete;
  ACE_Errno_Guard &operator= (const ACE_Errno_Guard &) = delete;

#if defined (ACE_MT_SAFE)
  ACE_ERRNO_TYPE *errno_ptr_;
#endif /* ACE_MT_SAFE */
  int error_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

// Inlining this class on debug builds with can cause
// deadlocks during static initialization. On non debug builds it
// causes compilation errors.
#if defined (ACE_HAS_INLINED_OSCALLS)
# if defined (ACE_INLINE)
#  undef ACE_INLINE
# endif /* ACE_INLINE */
# define ACE_INLINE inline
# include "ace/OS_Errno.inl"
#endif /* ACE_HAS_INLINED_OSCALLS */

#include /**/ "ace/post.h"
#endif /* ACE_OS_ERRNO_H */
