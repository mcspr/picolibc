/* legacy PROGMEM _P functions. no longer needed, but kept for backwards compatibility reasons */

#ifndef _MACHINE_STDIO_H_
#define _MACHINE_STDIO_H_

#define __need_size_t
#include <stddef.h>
#include <stdarg.h>

#include <sys/cdefs.h>

#ifdef __cplusplus
extern "C" {
#endif

int     printf_P(const char *__fmt, ...) __picolibc_format(printf, 1, 2);
int     sprintf_P(char *__s, const char *__fmt, ...) __picolibc_format(printf, 2, 3);
int     snprintf_P(char *__s, size_t __n, const char *__fmt, ...) __picolibc_format(printf, 3, 4);
int     vsnprintf_P(char *__s, size_t __n, const char *__fmt, __gnuc_va_list ap) __picolibc_format(printf, 3, 0);

#ifdef __cplusplus
}
#endif

#endif /* _MACHINE_STDIO_H_ */
