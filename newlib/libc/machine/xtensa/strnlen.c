#if _XTENSA_CSTRING_PGMSPACE_
#include <picolibc.h>

#define __need_size_t
#include <stddef.h>

#undef __STRICT_ANSI__
#include <string.h>

#include <sys/string.h>
#include <sys/pgmspace.h>

size_t
newlib_strnlen(const char *, size_t)
__attribute__((visibility("hidden")));

#define strnlen newlib_strnlen
#endif
#include "../../string/strnlen.c"
#if _XTENSA_CSTRING_PGMSPACE_
#undef strnlen

size_t
strnlen(const char *s, size_t n)
{
    if (__pgm_expected(s))
        return strnlen_P(s, n);

    return newlib_strnlen(s, n);
}
#endif
