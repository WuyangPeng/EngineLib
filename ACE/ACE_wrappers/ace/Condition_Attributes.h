// -*- C++ -*-

//==========================================================================
/**
 *  @file    Condition_Attributes.h
 *
 *  @author Douglas C. Schmidt <d.schmidt@vanderbilt.edu>
 */
//==========================================================================

#ifndef ACE_CONDITION_ATTRIBUTES_H
#define ACE_CONDITION_ATTRIBUTES_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/OS_NS_Thread.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Export ACE_Condition_Attributes
{
public:
  /// Constructor
  ACE_Condition_Attributes (int type = ACE_DEFAULT_SYNCH_TYPE);

  /// Destructor
  ~ACE_Condition_Attributes ();

  /// Accessor for retrieving the current attributes
  const ACE_condattr_t& attributes () const;

protected:
  /// The attributes
  ACE_condattr_t attributes_;

private:
  void operator= (const ACE_Condition_Attributes &) = delete;
  ACE_Condition_Attributes (const ACE_Condition_Attributes &) = delete;
};

template <class TIME_POLICY>
class ACE_Condition_Attributes_T : public ACE_Condition_Attributes
{
public:
  /// Constructor
  ACE_Condition_Attributes_T (int type = ACE_DEFAULT_SYNCH_TYPE)
    : ACE_Condition_Attributes (type)
  {}

  /// Destructor
  ~ACE_Condition_Attributes_T () = default;

private:
  void operator= (const ACE_Condition_Attributes_T<TIME_POLICY> &) = delete;
  ACE_Condition_Attributes_T (const ACE_Condition_Attributes_T<TIME_POLICY> &) = delete;
};

class ACE_Monotonic_Time_Policy;

template <>
class ACE_Export ACE_Condition_Attributes_T<ACE_Monotonic_Time_Policy>
  : public ACE_Condition_Attributes
{
public:
  /// Constructor
  ACE_Condition_Attributes_T (int type = ACE_DEFAULT_SYNCH_TYPE);

  /// Destructor
  ~ACE_Condition_Attributes_T () = default;

private:
  void operator= (const ACE_Condition_Attributes_T<ACE_Monotonic_Time_Policy> &) = delete;
  ACE_Condition_Attributes_T (const ACE_Condition_Attributes_T<ACE_Monotonic_Time_Policy> &) = delete;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Condition_Attributes.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_CONDITION_ATTRIBUTES_H */
