// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CoreDarwinBoot.h>
#include <stdarg.h>
#include <stdio.h>

extern void _putchar(char);

void CDBLog(const char *fmt, ...)
{
    va_list list;

    va_start(list, fmt);
    vprintf(fmt, list);
    _putchar('\r');
    va_end(list);
}

void panic(const char *fmt, ...)
{
    va_list list;

    va_start(list, fmt);
    vprintf(fmt, list);
    _putchar('\r');
    va_end(list);

    int i = 1;
    while (1) {
        i++; /* This will just straight up prevent further execution on one core. */
    }
};
