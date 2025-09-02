// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/libc.h>
#include <CorePlatform/Foundation.h>

bool DeviceConformsTo(PlatformDevice *Dev, const char *Compatible)
{
    /* TODO: multiple compatibles. */
    size_t comp = Dev->NumCompatibles;

    while (comp--) {
        if (memcmp(Dev->Compatible[comp], Compatible, strlen(Dev->Compatible[comp])) == 0) {
            return true;
        }
    }
    return false;
}

bool InitPlatformDevice(PlatformDevice *Dev, const char *Compatible)
{
    /* Safeguard. We _should_ initiate a panic if this returns false. */
    if (Dev == NULL || Compatible == NULL) {
        return false;
    }

    Dev->Compatible = &Compatible;
    Dev->NumCompatibles = 1;
    return true;
}
