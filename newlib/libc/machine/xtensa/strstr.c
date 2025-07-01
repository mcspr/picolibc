#if !_XTENSA_CSTRING_PGMSPACE_
/* ESP8266 has this in ROM */
#else
#include <string.h>

#include <sys/string.h>
#include <sys/pgmspace.h>

char *
strstr(const char *haystack, const char *needle)
{
    extern char *rom_strstr(const char *, const char *);
    if (__pgm_expected(needle))
        return strstr_P(haystack, needle);

    return rom_strstr(haystack, needle);
}
#endif
