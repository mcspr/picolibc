#define _DEFAULT_SOURCE
#include <sys/types.h>

#define __need_size_t
#include <stddef.h>

#include <wchar.h>
#include <sys/pgmspace.h>

size_t
wcsnlen (const wchar_t *s, size_t maxlen)
{
  const wchar_t *p;

  p = s;
  while (pgm_read_wchar(p) && maxlen-- > 0)
    p++;

  return (size_t)(p - s);
}
