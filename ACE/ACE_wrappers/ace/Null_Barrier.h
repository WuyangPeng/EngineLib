// -*- C++ -*-

//==========================================================================
/**
 *  @file    Null_Barrier.h
 *
 *  @author Douglas C. Schmidt <d.schmidt@vanderbilt.edu>
 */
//==========================================================================

#ifndef ACE_NULL_BARRIER_H
#define ACE_NULL_BARRIER_H
#include /**/ "ace/pre.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Null_Barrier
 *
 * @brief Implements "NULL barrier synchronization".
 */
class ACE_Null_Barrier
{
public:
  /// Initialize the barrier to synchronize <count> threads.
  ACE_Null_Barrier (unsigned int,
                    const char * = 0,
                    void * = 0) {}

  /// Default dtor.
  ~ACE_Null_Barrier () = default;

  /// Block the caller until all <count> threads have called <wait> and
  /// then allow all the caller threads to continue in parallel.
  int wait () { return 0; }

  /// Dump the state of an object.
  void dump () const {}

  /// Declare the dynamic allocation hooks.
  //ACE_ALLOC_HOOK_DECLARE;

private:
  void operator= (const ACE_Null_Barrier &) = delete;
  ACE_Null_Barrier (const ACE_Null_Barrier &) = delete;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* ACE_NULL_BARRIER_H */
