#define __need_size_t
#include <stddef.h>

#include <wchar.h>

#include <sys/pgmspace.h>

size_t
wcslen (const wchar_t * s)
{
  const wchar_t *p;

  p = s;
  while (pgm_read_wchar(p))
    p++;

  return p - s;
}
