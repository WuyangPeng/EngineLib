// -*- C++ -*-
#include "ace/Log_Category.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE int
ACE_Dirent::open (const ACE_TCHAR *dirname)
{
  // If the directory stream is already open, close it to prevent
  // possible resource leaks.
  if (this->dirp_)
    {
      ACE_OS::closedir (this->dirp_);
      this->dirp_ = nullptr;
    }

  this->dirp_ = ACE_OS::opendir (dirname);

  if (!this->dirp_)
    return -1;
  else
    return 0;
}

ACE_INLINE
ACE_Dirent::ACE_Dirent (const ACE_TCHAR *dirname)
{
  if (this->open (dirname) == -1)
    ACELIB_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Dirent::ACE_Dirent")));
}

ACE_INLINE
ACE_Dirent::~ACE_Dirent ()
{
  if (this->dirp_)
    ACE_OS::closedir (this->dirp_);
}

ACE_INLINE ACE_DIRENT *
ACE_Dirent::read ()
{
  return this->dirp_ ? ACE_OS::readdir (this->dirp_) : nullptr;
}

ACE_INLINE void
ACE_Dirent::close ()
{
  if (this->dirp_)
    {
      ACE_OS::closedir (this->dirp_);

      // Prevent double closure
      this->dirp_ = nullptr;
    }
}

ACE_INLINE void
ACE_Dirent::rewind ()
{
  if (this->dirp_)
    ACE_OS::rewinddir (this->dirp_);
}

ACE_INLINE void
ACE_Dirent::seek (long loc)
{
  if (this->dirp_)
    ACE_OS::seekdir (this->dirp_, loc);
}

ACE_INLINE long
ACE_Dirent::tell ()
{
  return this->dirp_ ? ACE_OS::telldir (this->dirp_) : 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL
