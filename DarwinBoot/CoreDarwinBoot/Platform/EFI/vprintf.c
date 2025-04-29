// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CoreDarwinBoot.h>
#include <Platform/EFI/EFI.h>

int platform_vprintf(const char *fmt, va_list list) {
    char c8[8000];
    wchar_t c16[8000];
    int ret = vsnprintf(c8, 8000, fmt, list);
    for (int i = 0; i < 8000; i++) {
        if (c8[i] == 0) {
            c16[i] = 0x0A; /* our \n */
            break;
        }
        c16[i] = c8[i];
    }
    ST->ConOut->OutputString(ST->ConOut, c16);
    memset(c16, 0, 8000 * 2);
    memset(c8, 0, 8000);
    return ret;
}