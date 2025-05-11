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

/* limits.h */

/* Use compiler definitions. */
#define CHAR_BIT __CHAR_BIT__

#define SCHAR_MIN -__SCHAR_MAX__ - 1
#define SCHAR_MAX __SCHAR_MAX__

#define UCHAR_MAX (SCHAR_MAX * 2) + 1

#define INT_MAX __INT_MAX__
#define UINT_MAX (INT_MAX * 2) + 1

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
void *memchr(const void *mem, int c, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
void *memset(void *dst, int x, size_t n);
int memcmp(const void *b1, const void *b2, size_t n);

int strncmp(const char *s1, const char *s2, size_t n);

size_t strlen(const char *str);

#endif
