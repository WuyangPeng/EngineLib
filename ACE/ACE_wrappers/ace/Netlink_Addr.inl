// -*- C++ -*-
#ifdef ACE_HAS_NETLINK

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE ACE_Netlink_Addr::ACE_Netlink_Addr ():
ACE_Addr (this->determine_type(), sizeof (sockaddr_nl))
{
  this->nl_.nl_family = AF_NETLINK;
}

ACE_INLINE void ACE_Netlink_Addr::set(int pid, int gid)
{
  this->nl_.nl_pid = pid;
  this->nl_.nl_groups = gid;
}

ACE_INLINE void ACE_Netlink_Addr::reset ()
{
  ACE_OS::memset (&this->nl_, 0, sizeof (this->nl_));
  this->nl_.nl_family = AF_NETLINK;
}

ACE_INLINE int ACE_Netlink_Addr::determine_type () const
{
  return AF_NETLINK;
}

ACE_INLINE void *ACE_Netlink_Addr::get_addr () const
{
  return (void*)&(this->nl_);
}

ACE_INLINE int ACE_Netlink_Addr::get_addr_size () const
{
  return sizeof(this->nl_);
}


ACE_INLINE void ACE_Netlink_Addr::set_addr (const void *addr, int len) {
  ACE_OS::memcpy (&this->nl_, addr, len);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_NETLINK */

