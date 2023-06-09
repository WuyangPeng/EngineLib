// -*- C++ -*-
#include "ace/OS_NS_sys_time.h"
#include "ace/High_Res_Timer.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE ACE_Time_Value_T<ACE_System_Time_Policy>
ACE_System_Time_Policy::operator()() const
{
  return ACE_Time_Value_T<ACE_System_Time_Policy> (ACE_OS::gettimeofday());
}

ACE_INLINE void
ACE_System_Time_Policy::set_gettimeofday (ACE_Time_Value (*)())
{
}

ACE_INLINE ACE_Time_Value_T<ACE_HR_Time_Policy>
ACE_HR_Time_Policy::operator()() const
{
  return ACE_Time_Value_T<ACE_HR_Time_Policy> (ACE_High_Res_Timer::gettimeofday_hr ());
}

ACE_INLINE void
ACE_HR_Time_Policy::set_gettimeofday (ACE_Time_Value (*)())
{
}

ACE_INLINE
ACE_FPointer_Time_Policy::ACE_FPointer_Time_Policy()
  : function_(ACE_OS::gettimeofday)
{
}

ACE_INLINE
ACE_FPointer_Time_Policy::
ACE_FPointer_Time_Policy(ACE_FPointer_Time_Policy::FPtr f)
  : function_(f)
{
}

ACE_INLINE ACE_Time_Value_T<ACE_FPointer_Time_Policy>
ACE_FPointer_Time_Policy::operator()() const
{
  return ACE_Time_Value_T<ACE_FPointer_Time_Policy> ((*this->function_)(), *this);
}

ACE_INLINE void
ACE_FPointer_Time_Policy::set_gettimeofday (ACE_Time_Value (*f)())
{
  this->function_ = f;
}

ACE_INLINE ACE_Time_Value_T<ACE_Delegating_Time_Policy>
ACE_Dynamic_Time_Policy_Base::operator()() const
{
  return this->gettimeofday ();
}

ACE_INLINE void
ACE_Dynamic_Time_Policy_Base::set_gettimeofday (ACE_Time_Value (*)())
{
}

ACE_INLINE ACE_Time_Value_T<ACE_Delegating_Time_Policy>
ACE_Delegating_Time_Policy::operator()() const
{
  return (*this->delegate_) ();
}

ACE_INLINE void
ACE_Delegating_Time_Policy::set_gettimeofday (ACE_Time_Value (*)())
{
}

ACE_INLINE void
ACE_Delegating_Time_Policy::set_delegate (ACE_Dynamic_Time_Policy_Base const * delegate)
{
  if (delegate)
    {
      this->delegate_ = delegate;
    }
}

ACE_END_VERSIONED_NAMESPACE_DECL
