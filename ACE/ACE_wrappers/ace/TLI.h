// -*- C++ -*-

//=============================================================================
/**
 *  @file    TLI.h
 *
 *  @author Doug Schmidt
 */
//=============================================================================


#ifndef ACE_TLI_H
#define ACE_TLI_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/OS_TLI.h"

#if defined (ACE_HAS_TLI)

#include "ace/IPC_SAP.h"
#include "ace/Addr.h"
#include "ace/os_include/os_fcntl.h"

// There's not a universal device name for TLI devices.  If the platform
// needs something other than /dev/tcp, it needs to be set up in the config.h
// file as ACE_TLI_TCP_DEVICE.
#ifndef ACE_TLI_TCP_DEVICE
#define ACE_TLI_TCP_DEVICE "/dev/tcp"
#endif

// There's not a universal device name for XTI/ATM devices.  If the platform
// needs something other than /dev/xtisvc0, it needs to be set up in the
// config.h file as ACE_XTI_ATM_DEVICE. This may be FORE vendor specific and
// there may be no good default.
#ifndef ACE_XTI_ATM_DEVICE
#define ACE_XTI_ATM_DEVICE "/dev/xtisvc0"
#endif

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_TLI
 *
 * @brief Defines the member functions for the base class of the
 * ACE_TLI  abstraction.
 */
class ACE_Export ACE_TLI : public ACE_IPC_SAP
{
public:
  /// Initialize a TLI endpoint.
  ACE_HANDLE open (const char device[],
                   int oflag = O_RDWR,
                   struct t_info *info = 0);

  /// Close a TLI endpoint and release resources.
  int close ();

  /// Set underlying protocol options.
  int set_option (int level, int option, void *optval, int optlen);

  /// Get underlying protocol options.
  int get_option (int level, int option, void *optval, int &optlen);

  // = Calls to underlying TLI operations.
  int look () const;
  int rcvdis (struct t_discon * = 0) const;
  int snddis (struct t_call * = 0) const;
  int sndrel () const;
  int rcvrel () const;

  /// Return our local endpoint address.
  int get_local_addr (ACE_Addr &) const;

  /// Dump the state of an object.
  void dump () const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  // = Ensure we are an abstract class.
  /// Default constructor.
  ACE_TLI ();

  /// Destructor.
  ~ACE_TLI ();

  /// Initialize a TLI endpoint.
  ACE_TLI (const char device[], int oflag = O_RDWR, struct t_info *info = 0);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/TLI.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_TLI */
#include /**/ "ace/post.h"
#endif /* ACE_TLI_H */
