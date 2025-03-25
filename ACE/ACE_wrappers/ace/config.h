#ifndef ACE_CONFIG_H
#define ACE_CONFIG_H

#if (defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)) && !defined(_CRAYC)
#include "config-linux.h"
#else // !defined(linux)
#include "config-win32.h"
#endif // defined(linux)

#endif /* ACE_CONFIG_H */

