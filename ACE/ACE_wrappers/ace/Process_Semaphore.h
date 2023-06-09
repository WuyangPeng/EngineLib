// -*- C++ -*-

//=============================================================================
/**
 *  @file    Process_Semaphore.h
 *
 *   Wrapper for Dijkstra style general semaphores that work
 *   across processes.
 *
 *  @author Douglas C. Schmidt <d.schmidt@vanderbilt.edu>
 */
//=============================================================================

#ifndef ACE_PROCESS_SEMAPHORE_H
#define ACE_PROCESS_SEMAPHORE_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !(defined (ACE_WIN32) || defined (ACE_HAS_POSIX_SEM))
# include "ace/SV_Semaphore_Complex.h"
#else
# include "ace/Semaphore.h"
#endif /* !(ACE_WIN32 || ACE_HAS_POSIX_SEM) */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Process_Semaphore
 *
 * @brief Wrapper for Dijkstra style general semaphores that work
 * across processes.
 */
class ACE_Export ACE_Process_Semaphore
{
public:
  /// Initialize the semaphore, with an initial value of @a count and a
  /// maximum value of @a max.
  ACE_Process_Semaphore (u_int count = 1, // By default make this unlocked.
                         const ACE_TCHAR *name = 0,
                         void * = 0,
                         int max = 0x7FFFFFFF);

  /**
   * Explicitly destroy the semaphore.  Note that only one thread
   * should call this method since it doesn't protect against race
   * conditions.
   */
  int remove ();

  /// Block the thread until the semaphore count becomes greater than
  /// 0, then decrement it.
  int acquire ();

  /**
   * Conditionally decrement the semaphore if count is greater than 0
   * (i.e., won't block).  Returns -1 on failure.  If we "failed"
   * because someone else already had the lock, @c errno is set to
   * @c EBUSY.
   */
  int tryacquire ();

  /// Increment the semaphore, potentially unblocking a waiting thread.
  int release ();

  /**
   * Acquire semaphore ownership.  This calls acquire() and is only
   * here to make the ACE_Process_Semaphore interface consistent
   * with the other synchronization APIs.
   */
  int acquire_read ();

  /**
   * Acquire semaphore ownership.  This calls acquire() and is only
   * here to make the ACE_Process_Semaphore interface consistent
   * with the other synchronization APIs.
   */
  int acquire_write ();

  /**
   * Conditionally acquire semaphore (i.e., won't block).  This calls
   * tryacquire() and is only here to make the ACE_Process_Semaphore
   * interface consistent with the other synchronization APIs.
   * Returns -1 on failure.  If we "failed" because someone else
   * already had the lock, @c errno is set to @c EBUSY.
   */
  int tryacquire_read ();

  /**
   * Conditionally acquire semaphore (i.e., won't block).  This calls
   * tryacquire() and is only here to make the ACE_Process_Semaphore
   * interface consistent with the other synchronization APIs.
   * Returns -1 on failure.  If we "failed" because someone else
   * already had the lock, @c errno is set to @c EBUSY.
   */
  int tryacquire_write ();

  /**
   * This is only here to make the ACE_Process_Semaphore
   * interface consistent with the other synchronization APIs.
   * Assumes the caller has already acquired the semaphore using one of
   * the above calls, and returns 0 (success) always.
   */
  int tryacquire_write_upgrade ();

#if defined (ACE_WIN32) || defined (ACE_HAS_POSIX_SEM)
  /// Return the underlying lock.
  const ACE_sema_t &lock () const;
#endif /* ACE_WIN32 || ACE_HAS_POSIX_SEM */

  /// Dump the state of an object.
  void dump () const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
#if defined (ACE_WIN32) || defined (ACE_HAS_POSIX_SEM)
  ACE_Semaphore lock_;
#else
  /// We need this to get the right semantics...
  ACE_SV_Semaphore_Complex lock_;
#endif /* ACE_WIN32 || ACE_HAS_POSIX_SEM */
};

/*****************************************************************************/

template <class T> class ACE_Malloc_Lock_Adapter_T;

/**
 * @brief Template specialization of ACE_Malloc_Lock_Adapter_T for
 * ACE_Process_Semaphore.
 *
 * This is needed since the constructor for ACE_Process_Semaphore doesn't match
 * the standard form used by other lock strategy classes.
 */
template<>
class ACE_Export ACE_Malloc_Lock_Adapter_T<ACE_Process_Semaphore>
{
public:
  ACE_Process_Semaphore * operator () (const ACE_TCHAR *name);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Process_Semaphore.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_PROCESS_SEMAPHORE_H */
