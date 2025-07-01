/* Backwards compatibility, both format and arguments are allowed to be PSTR / PROGMEM */

#define __need_size_t
#include <stddef.h>

#include <stdio.h>
#include <stdarg.h>

int vsnprintf_P(char* __s, size_t __n, const char *__fmt, __gnuc_va_list ap) {
    return vsnprintf(__s, __n, __fmt, ap);
}
