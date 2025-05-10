// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/libc_compat.h>

void *memchr(void *mem, int c, size_t n) {
    uint8_t *u8m = mem;
    uint8_t c8 = c;

    while (n--) {
        if (*u8m == c) {
            return u8m;
        } else {
            u8m++;
        }
    }

    return NULL;
}
