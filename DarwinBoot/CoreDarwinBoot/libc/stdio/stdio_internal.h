// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/libc_compat.h>

/* vprintf interface - handled by the platform */

/*
 * UEFI: /DarwinBoot/CoreDarwinBoot/Platform/EFI/vprintf.c
 * ARM: !!! TODO !!!
 */
extern int platform_vprintf(const char *fmt, va_list list);
