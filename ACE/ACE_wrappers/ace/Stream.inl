// -*- C++ -*-
ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <ACE_SYNCH_DECL, class TIME_POLICY> ACE_INLINE ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *
ACE_Stream<ACE_SYNCH_USE, TIME_POLICY>::head ()
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE, TIME_POLICY>::head");
  return this->stream_head_;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> ACE_INLINE ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *
ACE_Stream<ACE_SYNCH_USE, TIME_POLICY>::tail ()
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE, TIME_POLICY>::tail");
  return this->stream_tail_;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> ACE_INLINE int
ACE_Stream<ACE_SYNCH_USE, TIME_POLICY>::wait ()
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE, TIME_POLICY>::wait");
  return this->final_close_.wait ();
}

template <ACE_SYNCH_DECL, class TIME_POLICY> ACE_INLINE int
ACE_Stream_Iterator<ACE_SYNCH_USE, TIME_POLICY>::next (const ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *&mod)
{
  ACE_TRACE ("ACE_Stream_Iterator<ACE_SYNCH_USE, TIME_POLICY>::next");
  mod = this->next_;
  return this->next_ != 0;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> ACE_INLINE int
ACE_Stream_Iterator<ACE_SYNCH_USE, TIME_POLICY>::done () const
{
  ACE_TRACE ("ACE_Stream_Iterator<ACE_SYNCH_USE, TIME_POLICY>::done");
  return this->next_ == 0;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Stream_Iterator<ACE_SYNCH_USE, TIME_POLICY>::advance ()
{
  ACE_TRACE ("ACE_Stream_Iterator<ACE_SYNCH_USE, TIME_POLICY>::advance");
  this->next_ = this->next_->next ();
  return this->next_ != 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL
