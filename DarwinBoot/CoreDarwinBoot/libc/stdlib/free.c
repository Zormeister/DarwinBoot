// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include "AllocWatchdog.h"
#include "stdlib_internal.h"

void free(void *mem)
{
    AllocWDGRemove(&gMemWDG, mem);
    return platform_free(mem);
}