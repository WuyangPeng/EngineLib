// -*- C++ -*-

//=============================================================================
/**
 *  @file Intrusive_List_Node.h
 *
 *  @author Carlos O'Ryan <coryan@uci.edu>
 */
//=============================================================================

#ifndef ACE_INTRUSIVE_LIST_NODE_H
#define ACE_INTRUSIVE_LIST_NODE_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Intrusive_List_Node
 *
 * @brief Implement the requirements for ACE_Intrusive_List
 *
 * The class should be used as follows:
 *
 * class My_Object : public ACE_Intrusive_List_Node<My_Object> {<BR>
 * ....<BR>
 * };<BR>
 *
 * However, ACE is supported on platforms that would surely get
 * confused using such templates, the class is provided as a helper
 * for our lucky users that only need portability to modern C++
 * compilers.
 */
template <class T>
class ACE_Intrusive_List_Node
{
public:
  /** @name Accesors and modifiers to the next and previous pointers
   *
   */
  //@{
  T *prev () const;
  void prev (T *);
  T *next () const;
  void next (T *);
  //@}

protected:
  /// Constructor
  /**
   * The constructor is protected, because only derived classes should
   * be instantiated.
   */
  ACE_Intrusive_List_Node () = default;

private:
  /// Head and tail of the list
  T *prev_ {};
  T *next_ {};
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Intrusive_List_Node.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Intrusive_List_Node.cpp"

#include /**/ "ace/post.h"
#endif /* ACE_INTRUSIVE_LIST_NODE_H */
