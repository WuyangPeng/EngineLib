// -*- C++ -*-
#include "ace/Log_Category.h"

#if defined (ACE_HAS_STRINGS)
#  include "ace/os_include/os_strings.h"
#endif /* ACE_HAS_STRINGS */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/// Initialize the bitmask to all 0s and reset the associated fields.
ACE_INLINE void
ACE_Handle_Set::reset ()
{
  ACE_TRACE ("ACE_Handle_Set::reset");
  this->max_handle_ = ACE_INVALID_HANDLE;
#if defined (ACE_HAS_BIG_FD_SET)
  this->min_handle_ = NUM_WORDS * WORDSIZE;
#endif /* ACE_HAS_BIG_FD_SET */
  this->size_ = 0;
  // #if !defined (ACE_HAS_BIG_FD_SET)      Why is this here?  -Steve Huston
  FD_ZERO (&this->mask_);
  // #endif /* ACE_HAS_BIG_FD_SET */
}

#if defined (ACE_HAS_BIG_FD_SET)
ACE_INLINE ACE_Handle_Set &
ACE_Handle_Set::operator = (const ACE_Handle_Set &rhs)
{
  ACE_TRACE ("ACE_Handle_Set::operator =");

  if (rhs.size_ > 0)
    {
      this->size_ = rhs.size_;
      this->max_handle_ = rhs.max_handle_;
      this->min_handle_ = rhs.min_handle_;
      this->mask_ = rhs.mask_;
    }
  else
    {
      this->reset ();
    }

  return *this;
}

ACE_INLINE
ACE_Handle_Set::ACE_Handle_Set (const ACE_Handle_Set &rhs)
{
  ACE_TRACE ("ACE_Handle_Set::ACE_Handle_Set");

  if (rhs.size_ > 0)
    {
      this->size_ = rhs.size_;
      this->max_handle_ = rhs.max_handle_;
      this->min_handle_ = rhs.min_handle_;
      this->mask_ = rhs.mask_;
    }
  else
    {
      this->reset ();
    }
}
#endif /* ACE_HAS_BIG_FD_SET */

/// Returns the number of the large bit.
ACE_INLINE ACE_HANDLE
ACE_Handle_Set::max_set () const
{
  ACE_TRACE ("ACE_Handle_Set::max_set");
  return this->max_handle_;
}

/// Checks whether handle is enabled.
ACE_INLINE int
ACE_Handle_Set::is_set (ACE_HANDLE handle) const
{
  ACE_TRACE ("ACE_Handle_Set::is_set");

  fd_set *set = const_cast<fd_set*> (&this->mask_);
  int ret = FD_ISSET (handle, set);

#if defined (ACE_HAS_BIG_FD_SET)
  ret = ret && this->size_ > 0;
#elif defined (ACE_VXWORKS) && ACE_VXWORKS >= 0x690
  ret = ret != 0;
#endif
  return ret;
}

/// Enables the handle.
ACE_INLINE void
ACE_Handle_Set::set_bit (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_Handle_Set::set_bit");
  if ((handle != ACE_INVALID_HANDLE)
      && (!this->is_set (handle)))
    {
#if defined (ACE_HANDLE_SET_USES_FD_ARRAY)
      FD_SET ((SOCKET) handle,
              &this->mask_);
      ++this->size_;
#else /* ACE_HANDLE_SET_USES_FD_ARRAY */
#if defined (ACE_HAS_BIG_FD_SET)
      if (this->size_ == 0)
        FD_ZERO (&this->mask_);

      if (handle < this->min_handle_)
        this->min_handle_ = handle;
#endif /* ACE_HAS_BIG_FD_SET */

      FD_SET (handle,
              &this->mask_);
      ++this->size_;

      if (handle > this->max_handle_)
        this->max_handle_ = handle;
#endif /* ACE_HANDLE_SET_USES_FD_ARRAY */
    }
}

/// Disables the handle.
ACE_INLINE void
ACE_Handle_Set::clr_bit (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_Handle_Set::clr_bit");

  if ((handle != ACE_INVALID_HANDLE) &&
      (this->is_set (handle)))
    {
      FD_CLR ((ACE_SOCKET) handle,
              &this->mask_);
      --this->size_;

#if !defined (ACE_HANDLE_SET_USES_FD_ARRAY)
      if (handle == this->max_handle_)
        this->set_max (this->max_handle_);
#endif /* !ACE_HANDLE_SET_USES_FD_ARRAY */
    }
}

/// Returns a count of the number of enabled bits.
ACE_INLINE int
ACE_Handle_Set::num_set () const
{
  ACE_TRACE ("ACE_Handle_Set::num_set");
#if defined (ACE_HANDLE_SET_USES_FD_ARRAY)
  return this->mask_.fd_count;
#else /* !ACE_HANDLE_SET_USES_FD_ARRAY */
  return this->size_;
#endif /* ACE_HANDLE_SET_USES_FD_ARRAY */
}

/// Returns a pointer to the underlying fd_set.
ACE_INLINE
ACE_Handle_Set::operator fd_set *()
{
  ACE_TRACE ("ACE_Handle_Set::operator fd_set *");

  if (this->size_ > 0)
    return (fd_set *) &this->mask_;
  else
    return nullptr;
}

/// Returns a pointer to the underlying fd_set.
ACE_INLINE fd_set *
ACE_Handle_Set::fdset ()
{
  ACE_TRACE ("ACE_Handle_Set::fdset");

  if (this->size_ > 0)
    return (fd_set *) &this->mask_;
  else
    return nullptr;
}

ACE_END_VERSIONED_NAMESPACE_DECL
