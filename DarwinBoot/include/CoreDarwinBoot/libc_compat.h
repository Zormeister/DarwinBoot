// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __LIBC_COMPAT__
#define __LIBC_COMPAT__

#include <CoreDarwinBoot/CDBBasicTypes.h>

/* ctype.h */
int isalnum(int c);
int isalpha(int c);
int isblank(int c);
int iscntrl(int c);
int isdigit(int c);
int isgraph(int c);
int islower(int c);
int isprint(int c);
int ispunct(int c);
int isspace(int c);
int isupper(int c);
int isxdigit(int c);
int tolower(int c);
int toupper(int c);

/* stdarg.h */
#define va_list __builtin_va_list
#define va_arg(va, type) __builtin_va_arg((va), type)
#define va_copy(va1, va2) __builtin_va_copy((va1), (va2))
#define va_start(va, arg) __builtin_va_start((va), arg)
#define va_end(va) __builtin_va_end((va))

/* stdio.h */
int printf(const char *fmt, ...);
int vprintf(const char *fmt, va_list list);

int snprintf(char *s, size_t n, const char *format, ...);
int vsnprintf(char *s, size_t n, const char *format, va_list va);

/* stdlib.h */
int atoi(const char *str);
long atol(const char *str);

void free(void *mem);

void *malloc(size_t size);
void *realloc(void *ptr, size_t size);

/* string.h */
void *memcpy(void *dest, const void *src, size_t n); // done
void *memset(void *dst, int x, size_t n); // done
int memcmp(const void *b1, const void *b2, size_t n); // how the FUCK do i properly do this

int strncmp(const char *s1, const char *s2, size_t n); // how the FUCK do i properly do thus

size_t strlen(const char *str);

#endif