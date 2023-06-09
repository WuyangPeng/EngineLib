// -*- C++ -*-
ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_Errno_Guard::ACE_Errno_Guard (ACE_ERRNO_TYPE &errno_ref,
                                  int error)
  :
#if defined (ACE_MT_SAFE)
    errno_ptr_ (&errno_ref),
#endif /* ACE_MT_SAFE */
    error_ (error)
{
#if !defined(ACE_MT_SAFE)
  ACE_UNUSED_ARG (errno_ref);
#endif /* ACE_MT_SAFE */
}

ACE_INLINE
ACE_Errno_Guard::ACE_Errno_Guard (ACE_ERRNO_TYPE &errno_ref)
  :
#if defined (ACE_MT_SAFE)
    errno_ptr_ (&errno_ref),
#endif /* ACE_MT_SAFE */
    error_ (errno_ref)
{
}

ACE_INLINE
ACE_Errno_Guard::~ACE_Errno_Guard ()
{
#if defined (ACE_MT_SAFE)
  *errno_ptr_ = this->error_;
#else
  errno = this->error_;
#endif /* ACE_MT_SAFE */
}

ACE_INLINE int
ACE_Errno_Guard::operator= (int error)
{
  return this->error_ = error;
}

ACE_INLINE bool
ACE_Errno_Guard::operator== (int error)
{
  return this->error_ == error;
}

ACE_INLINE bool
ACE_Errno_Guard::operator!= (int error)
{
  return this->error_ != error;
}

ACE_END_VERSIONED_NAMESPACE_DECL
