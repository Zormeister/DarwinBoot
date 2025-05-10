// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <Drivers/Driver.h>
#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <CorePlatform/Foundation.h>
#include <Drivers/Serial/PL011UART.h>

MMIODevice UART0;

extern PlatformDeviceDescriptor platform_devices[];

void platform_init() {
#if EARLY_BOOT_LOG
    /* First, establish our UART0 device. */
    InitMMIODevice(&UART0, platform_devices[0].Range.RangeStart, platform_devices[0].Range.RangeSize);
#endif
}
