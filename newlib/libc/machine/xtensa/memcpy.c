#if !_XTENSA_CSTRING_PGMSPACE_
/* ESP8266 has this in ROM */
#else
#define _GNU_SOURCE
#include <stddef.h>

#include <string.h>
#include <sys/string.h>
#include <sys/pgmspace.h>

#undef memcpy

#include <stdio.h>

void *
memcpy(void *__restrict dest, const void *__restrict src, size_t n)
{
    extern void *__fast_memcpy(void *__restrict, const void *__restrict, size_t);
    if (__pgm_expected(src))
        return memcpy_P(dest, src, n);

    return __fast_memcpy(dest, src, n);
}
#endif
