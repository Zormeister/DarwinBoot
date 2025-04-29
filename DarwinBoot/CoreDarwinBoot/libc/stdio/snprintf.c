// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/libc_compat.h>

int snprintf(char *s, size_t n, const char *format, ...) {
    va_list list;
    va_start(list, format);
    int ret = vsnprintf(s, n, format, list);
    va_end(list);
    return ret;
}