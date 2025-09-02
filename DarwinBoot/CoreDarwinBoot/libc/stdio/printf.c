// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/libc.h>
#include <External/printf/printf.h>

#undef printf

int printf(const char *fmt, ...)
{
    va_list list;
    va_start(list, fmt);
    int ret = vprintf(fmt, list);
    va_end(list);
    return ret;
}
