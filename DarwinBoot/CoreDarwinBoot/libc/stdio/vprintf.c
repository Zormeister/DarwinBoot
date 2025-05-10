// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/libc_compat.h>
#include "stdio_internal.h"

int vprintf(const char *fmt, va_list list) {
    return platform_vprintf(fmt, list);
}
