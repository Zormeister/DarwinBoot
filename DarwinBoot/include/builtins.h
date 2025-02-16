// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __has_builtin
#define __has_builtin(x) 0
#endif

/* sigh... I'll get there eventually. */

#if __has_builtin(__builtin_bswap16)
#define DBByteSwap16(bytes) (unsigned short)__builtin_bswap16(bytes)
#endif

#if __has_builtin(__builtin_bswap32)
#define DBByteSwap32(bytes) (unsigned int)__builtin_bswap32(bytes)
#endif

#if __has_builtin(__builtin_bswap64)

#ifdef __clang__
/* GCC alterative tbd */
#define DBByteSwap64(bytes) (unsigned long long)__builtin_bswap64(bytes)
#endif

#endif