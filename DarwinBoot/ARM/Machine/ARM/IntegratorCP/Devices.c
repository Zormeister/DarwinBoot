// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <CorePlatform/Foundation.h>

#include <Machine/ARM/IntegratorCP/MemoryMap.h>

PlatformDeviceDescriptor platform_devices[] = {
    {"uart,arm-pl011", 2, 
        {
            {UART0_BASE, 0x1000},
            {UART1_BASE, 0x1000}
        }}, /* I didn't research the reg size. I'll fix this later. */

    {NULL, 0, {}},
};

