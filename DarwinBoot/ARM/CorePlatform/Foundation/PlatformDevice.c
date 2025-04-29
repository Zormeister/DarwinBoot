// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CorePlatform/Foundation.h>
#include <CoreDarwinBoot/libc_compat.h>

bool DeviceConformsTo(PlatformDevice *Dev, const char *Compatible) {
    /* TODO: multiple compatibles. */
    if (memcmp(Dev->Compatible, Compatible, strlen(Dev->Compatible)) == 0) {
        return true;
    }
    return false;
}

bool InitPlatformDevice(PlatformDevice *Dev, const char *Compatible) {
    /* Safeguard. We _should_ initiate a panic if this returns false. */
    if (Dev == NULL || Compatible == NULL) { return false; } 

    Dev->Compatible = Compatible;
    return true;
}
