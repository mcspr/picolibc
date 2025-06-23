/*
 strnlen_P.c - string function that supports PROGMEM

 Modified from original source by Earle F. Philhower, III
 Original authorship:
 Copyright (c) 2015 Michael C. Miller.  All right reserved.

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#define __need_size_t
#include <stddef.h>

#include <stdint.h>

#include <sys/string.h>
#include <sys/pgmspace.h>

static const uint32_t *__strnlen_P_aux (const uint32_t*, uint32_t);
static const uint32_t *
__strnlen_P_aux(const uint32_t* p, uint32_t w) {
    for (size_t n = 0; n < 4; ++n)
      if (!(w & ((uint32_t)0xff << (n * 8))))
        return p + n;

    return NULL;
}

static size_t __strnlen_P_count_misaligned(const char **cp, size_t size);
static size_t __strnlen_P_count_misaligned(const char **cp, size_t size) {
    const char *c = *cp;
    while ((size > 0) && (uintptr_t)c & 0x3) {
      if (!pgm_read_byte(c)) {
        size = 0;
        goto out;
      }

      --size;
      ++c;
    }

out:
    *cp = c;
    return size;
}

static size_t __strnlen_P_count_leftover(const char **, size_t);
static size_t __strnlen_P_count_leftover(const char **cp, size_t size) {
    const char *c = *cp;
    while (size > 0) {
      if (!pgm_read_byte(c)) {
        size = 0;
        goto out;
      }

      --size;
      ++c;
    }

out:
    *cp = c;
    return size;
}

size_t
strnlen_P(const char* s, size_t size)
{
    const char *cp = s;
    const uint32_t *pmem, *tmp;

    // Take care of any misaligned starting data
    if (!(size = __strnlen_P_count_misaligned(&cp, size)))
      goto done;

    // We didn't find the end in the initial misaligned bits
    // Now try it 32-bits at a time while possible
    pmem = (const uint32_t*) cp;
    while (size > 3) {
      if ((tmp = __strnlen_P_aux(pmem, *pmem)) != NULL) {
        cp = (const char*) tmp;
        goto done;
      }

      pmem++;
      size -= 4;
    }

    // Take care of any straggling bytes
    __strnlen_P_count_leftover(&cp, size);

done:
    return (size_t) (cp - s);
}
