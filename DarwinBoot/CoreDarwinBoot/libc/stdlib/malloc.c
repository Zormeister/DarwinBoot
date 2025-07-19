// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include "AllocWatchdog.h"
#include "stdlib_internal.h"
#include <CoreDarwinBoot/libc_compat.h>

void *malloc(size_t size)
{
    void *ret = platform_malloc(size);

    /* Initialize memory watchdog here. */
    if (gMemWDG.Revision == 0) {
        AllocWDGInit(&gMemWDG);
    }

    AllocWDGAdd(&gMemWDG, ret, size);
    return ret;
}