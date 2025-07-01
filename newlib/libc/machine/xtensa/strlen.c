#if !_XTENSA_CSTRING_PGMSPACE_
/* ESP8266 has this in ROM */
#else
#define __need_size_t
#include <stddef.h>

#include <string.h>
#include <sys/pgmspace.h>

#include "pgmspace/_pgmspace.h"

size_t
strlen(const char *s)
{
    extern size_t __fast_strlen(const char*);
    if (__pgm_expected(s))
        return strlen_P(s);

    return __fast_strlen(s);
}
#endif
