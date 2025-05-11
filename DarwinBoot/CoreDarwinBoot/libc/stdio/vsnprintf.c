// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/libc_compat.h>

/* I'm not even going to bother with floating point types. */
int vsnprintf(char *s, size_t n, const char *format, va_list va) {
    size_t ceiling = n;
    size_t tracker = 0;

    for (const char *p = format; (*p != '\0') && (tracker < ceiling); ++p) {
        if (*p == '%') {
            switch (*++p) {
                case '\0':
                case ' ':
                    /* This means we're at a % with no fmt. Treat it like a regular character. */
                    s[tracker] = *p;
                    tracker++;
                    break;
                case 'i':
                case 'd': {
                    int a = va_arg(va, int);
                    break;
                }
                case 'x': {
                    int arg = va_arg(va, int);
                    int c = arg;
                    size_t ndigits = 0;
                    while (c >>= 4 && c > 0) {
                        ndigits++;
                    }
                    break;
                }
                case 'z': /* size_t */
                    switch (*++p) {
                        case 'x': { /* x means we want it as a HEXADECIMAL value */
                            size_t arg = va_arg(va, size_t);
                            /* ok now how exactly am i supposed to turn 92876289 to a string */
                            size_t c = arg;
                            size_t ndigits = 0;
                            while (c >>= 4 && c > 0) {
                                ndigits++;
                            }
                        }
                    }
                case 's': {
                    const char *str = va_arg(va, const char *);
                    size_t size = strlen(str);
                    for (size_t idx = 0; idx < size; idx++) {
                        s[tracker] = str[idx];
                        tracker++;
                    }
                    break;
                }
            }
        } else {
            /* otherwise copy the character and iterate */
            s[tracker] = *p;
            tracker++;
        }
    }

    return 0;
}
