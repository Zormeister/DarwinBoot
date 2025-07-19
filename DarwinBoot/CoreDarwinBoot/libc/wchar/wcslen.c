// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/libc_compat.h>

size_t wcslen(const wchar_t *str)
{
    size_t ret = 0;
    const wchar_t *string = str;

    while (*string != 0) {
        string++;
        ret++;
    }

    return ret;
}
