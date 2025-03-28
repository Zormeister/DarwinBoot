// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __LIBC_COMPAT__
#define __LIBC_COMPAT__

#include <CoreDarwinBoot/CDBBasicTypes.h>

/* string.h */
void *memcpy(void *dest, const void *src, size_t n); // done
void *memset(void *dst, int x, size_t n); // done
int memcmp(const void *b1, const void *b2, size_t n); // how the FUCK do i properly do this

int strncmp(const char *s1, const char *s2, size_t n); // how the FUCK do i properly do thus

size_t strlen(const char *str);

#endif