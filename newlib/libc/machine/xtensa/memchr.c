#define _DEFAULT_SOURCE 1
#define __MISC_VISIBLE 1
#define __USE_MISC 1

#include <string.h>

void *
newlib_memchr(const void *, int, size_t);

#define memchr newlib_memchr
#include "../../string/memchr.c"
#undef memchr

#include <stddef.h>

#include <sys/string.h>
#include <sys/pgmspace.h>

void *
memchr(const void *s, int c, size_t n)
{
    if (__pgm_expected(s))
        return memchr_P(s, c, n);

    return newlib_memchr(s, c, n);
}
