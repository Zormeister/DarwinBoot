// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/libc_compat.h>

void *memset(void *dest, int x, size_t n) {
    if (dest == NULL) {
#ifdef LIBC_PANIC_ON_NULLPTR
        panic("memset: bad pointer inputted");
#endif
        return NULL;
    }

    uint8_t *dst = dest;
    for (size_t i = 0; i < n; i++) {
        dst[i] = x; // what if i told you sizeof(char) < sizeof(int)
    }
    return dst;
}
