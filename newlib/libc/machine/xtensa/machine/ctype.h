#ifndef _MACHINE_CTYPE_H_
#define _MACHINE_CTYPE_H_

#include <sys/pgmspace.h>

#define __ctype_lookup(__c) pgm_read_byte(&(__CTYPE_PTR + 1)[(int) (__c)])
#define __ctype_lookup_l(__c, __l) pgm_read_byte(&((__CTYPE_PTR_L(__l)+1)[(int)(__c)]))

#endif /* _MACHINE_CTYPE_H_ */
