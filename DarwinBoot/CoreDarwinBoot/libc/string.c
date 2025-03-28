// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/libc_compat.h>

/* should i be an elitist and not have null pointer checks */

/* should i do it in 64-bit chunks instead? */
/* that would make better use of the 64-bit registers on ARM and x86_64, but what about hypothetical ARMv7 ports? */
void *memcpy(void *dest, const void *src, size_t n) {
    if (dest == NULL || src == NULL) {
#ifdef LIBC_PANIC_ON_NULLPTR
        panic("memcpy: bad values inputted");
#endif
        return NULL; 
    }

    uint8_t *dst = dest;
    const uint8_t *source = src;
    for (size_t i = 0; i < n; i++) {
        dst[i] = source[i];
    }
    return dst;
}

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

size_t strlen(const char *str) {
    if (str == NULL) {
#ifdef LIBC_PANIC_ON_NULLPTR
        panic("strlen: bad string pointer");
#endif
        return 0;
    }

    size_t ret = 0;
    const char *string = str;

    while (*string != 0) {
        string++;
        ret++;
    }

    return ret;
}