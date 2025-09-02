// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include "AllocWatchdog.h"
#include "stdlib_internal.h"
#include <CoreDarwinBoot/libc.h>

void free(void *mem)
{
    AllocWDGRemove(&gMemWDG, mem);
    return platform_free(mem);
}