/* Copyright 2017 Yaakov Selkowitz <yselkowi@redhat.com> */
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ssp/ssp.h>
#undef puts

static void (*fortify_handler)(int sig);

#include "../machine/xtensa/sys/pgmspace.h"
static const char CHK_FAIL_MSG[] PSTR_ATTR =
    "*** overflow detected ***: terminated"
#ifndef __TINY_STDIO
    "\n"
#endif
;

__noreturn void
__chk_fail(void)
{
#ifdef __TINY_STDIO
  puts(CHK_FAIL_MSG);
#else
  write (2, msg, sizeof(CHK_FAIL_MSG)-1);
#endif
  if (fortify_handler)
      (*fortify_handler)(SIGABRT);
  abort();
}

void
set_fortify_handler (void (*handler) (int sig))
{
    fortify_handler = handler;
}
