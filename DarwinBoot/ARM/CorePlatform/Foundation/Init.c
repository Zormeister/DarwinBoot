// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CorePlatform/Foundation.h>

/* Initialise mapper by establishing our callbacks and calling PageMapperInit(EarlyMem) */
bool CPInitialize(MemoryRange EarlyMem, PlatformDeviceDescriptor *Devices) {
    /* EARLY INIT >>> */

#if __ARM_ARCH__ == 8
/* ARMv8 */
#elif __ARM_ARCH__ == 7

#elif __ARM_ARCH__ == 6
#endif

    return true;
}
