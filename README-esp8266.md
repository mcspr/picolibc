Based on newlib v4.0.0 from https://github.com/earlephilhower/newlib-xtensa/ by Earle F. Philhower, III
Using parts of the original patch on top of newlib-2.0.0 by Angus Gratton and `..._P` compatibility funcs by Michael C. Miller

```bash
# configuration works something like this
$ scripts/do-configure xtensa-lx106-elf \
    -Dprefix=/where/to/install/prefix \
    -Dio-long-long=true \
    -Dnewlib-have-fcntl=false \
    -Dsysroot-install=true \
    -Dsysroot-install-skip-checks=true \
    -Dnewlib-global-atexit=true \
    -Dio-c99-formats=true \
    -Dnewlib-wide-orient=false \
    -Dnewlib-stdio64=false \
    -Dnewlib-unbuf-stream-opt=true \
    -Dio-pos-args=true \
    -Dposix-console=false \
    -Dfast-bufio=true \
    -Dtinystdio=true \
    -Denable-malloc=false \
    -Dsystem-libc=true \
    -Dpicocrt=true \
    ""
```

Compared to newlib-xtensa v4.0.0
- libc/sys no longer used. libc/machine contains all extra non-libc code and override headers are configured through builder recipes (meson, cmake)
- libc/machine files override stdlib / string / etc. files by using the same name, removing the need for `#if 0 ... #endif` wrapper
  Machine files provide `avr-libc` compatibility layer via `PROGMEM`, `..._P` functions and `sys/pgpspace.h`, just like the newlib-xtensa does.
- tinystdio is enabled instead of the newlib stdiolib. should help w/ compatibility woes compared to newlib 4.5.0+ that removes `wchar_t` functions when nano-printf is enabled
- Tree is still heavily modified to support systems without unaligned load exception handler set up by using `pgm_...` macros.
  *Most* stdio & stdlib & string functions explicitly check for source address location and choose from either rom, picolibc or `..._P` implementation.

While Espressif provides semi-recent versions of newlib & picolibc
- xtensa-config.h assumes esp32+, floating point ops availability, various asm routines sometimes hardcode windowed abi calls
- there is no libgloss and no need to link it. espressif opted into using it as syscall & .ld script installer, also removing libc/sys/xtensa

ref. [espressif/newlib-esp32 "newlib-esp32 based on 4.3.0"](https://github.com/espressif/newlib-esp32/commit/4319e8a02e15c8bc836696901885f9f0a0a6a51c)
ref. [espressif/pibolib "esp-1.8.6, based on v1.8.6"](https://github.com/espressif/picolibc/commits/esp-1.8.6/)

