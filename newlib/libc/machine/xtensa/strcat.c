#if _XTENSA_CSTRING_PGMSPACE_
#include <string.h>
#undef strcat

char *
newlib_strcat(char *__restrict, const char *__restrict)
__attribute__((visibility("hidden")));

#define strcat newlib_strcat
#endif
#include "../../string/strcat.c"
#if _XTENSA_CSTRING_PGMSPACE_
#undef strcat

#include <sys/string.h>
#include <sys/pgmspace.h>

char *
strcat(char *__restrict dest, const char *__restrict src)
{
    if (__pgm_expected(src))
        return strcat_P(dest, src);

    return newlib_strcat(dest, src);
}
#endif
