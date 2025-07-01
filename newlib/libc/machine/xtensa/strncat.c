#if _XTENSA_CSTRING_PGMSPACE_
#include <string.h>
#undef strcat

#define __need_size_t
#include <stddef.h>

char *
newlib_strncat(char *, const char *__restrict, size_t)
__attribute__((visibility("hidden")));

#define strncat newlib_strncat
#endif
#include "../../string/strncat.c"
#if _XTENSA_CSTRING_PGMSPACE_
#undef strncat

#include <sys/string.h>
#include <sys/pgmspace.h>

char *
strncat(char *dest, const char *__restrict src, size_t n)
{
    if (__pgm_expected(src))
        return strncat_P(dest, src, n);

    return newlib_strncat(dest, src, n);
}
#endif
