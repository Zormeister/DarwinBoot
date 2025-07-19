// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CoreDarwinBoot.h>
#include <CorePlatform/Foundation.h>
#include <CorePlatform/MemoryManager.h>

/* Initialise mapper by establishing our callbacks and calling PageMapperInit(EarlyMem) */
bool CPInitialize(MemoryRange EarlyMem, PlatformDeviceDescriptor *Devices)
{
    /* EARLY INIT >>> */

    if (CPMemoryManagerInit(&EarlyMem, 1) == false) {
        /* Well fuck. */
        panic("[CorePlatform]: what the actual fuck");
    }

    return true;
}
