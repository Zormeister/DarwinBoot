// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/libc_compat.h>

void *memchr(const void *mem, int c, size_t n)
{
    const uint8_t *u8m = mem;

    while (n--) {
        if (*u8m == c) {
            return (void *)u8m;
        } else {
            u8m++;
        }
    }

    return NULL;
}
