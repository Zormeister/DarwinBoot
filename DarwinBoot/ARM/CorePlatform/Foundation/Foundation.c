// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CorePlatform/Foundation.h>
#include <CoreDarwinBoot/libc_compat.h>

/* TODO: reloc? */
char BootMessage[] = {
    "=======================================\n"
    "::\n"
    /*  <Payload> <Board Config> */
    ":: %s for %s, Copyright (C) 2024-2025 Zormeister\n"
    "::\n"
    ":: BUILD_TAG: %s\n"
    "::\n"
    ":: BUILD_STYLE: %s\n"
    "::\n"
    ":: CPID: %04x BORD: %02x \n"
    "::\n"
    "=======================================\n"
};

/* FOUNDATION */

int platform_vprintf(const char *fmt, va_list list) {
    char buf[8000];
    int ret = vsnprintf(buf, 8000, fmt, list);

    /* Now, write to serial */

    memset(buf, 0, 8000);
    return ret;
}
