// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/libc_compat.h>
#include <External/printf/printf.h>

#undef vsnprintf

/* I'm not even going to bother with floating point types. */
int vsnprintf(char *s, size_t n, const char *format, va_list va) {
    return vsnprintf_(s, n, format, va);
}
