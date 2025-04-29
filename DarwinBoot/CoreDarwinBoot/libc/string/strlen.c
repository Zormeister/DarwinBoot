// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/libc_compat.h>

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
