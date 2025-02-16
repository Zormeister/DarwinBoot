// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once

/* tyvm to POSIX-UEFI for the details on how to have an independent libc */

/* give us some good old stdint  */

typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

/* some familar <libkern/OSTypes.h> looks nice */
typedef int8_t SInt8;
typedef int16_t SInt16;
typedef int32_t SInt32;
typedef uint8_t UInt8;
typedef uint16_t UInt16;
typedef uint32_t UInt32;

#define NULL (void *)0

/* and some stdbool */
typedef _Bool bool;
#define true 1
#define false 0

#ifdef __cplusplus
#if __cplusplus < 201703L
#error This project uses C 17, please use C 17 for compilation/your LSP
#endif
#endif
#if defined (__STDC_VERSION__)
#if __STDC_VERSION__ < 201710L
#error This project uses C 17, please use C 17 for compilation/your LSP
#endif
#endif

#ifndef __cplusplus
typedef uint16_t wchar_t;
#endif

/* LLVM exclusive stuff. */
#ifdef __clang__
#define BUILD_TOOL "LLVM/Clang"
#define COMPILER_VERSION_MAJOR __clang_major__
#define COMPILER_VERSION_MINOR __clang_minor__
#define COMPILER_VERSION_PATCH __clang_patchlevel__
#define COMPILER_VERSION __clang_version__

typedef long long int64_t;
typedef unsigned long long uint64_t;
typedef unsigned long long uintptr_t;

// This is annoying because compiler diffs but oh well
#define WSTRING(str) u##str
#endif

#ifdef _MSC_VER
#warning i haven't tested this

typedef long long int64_t;
typedef unsigned long long uint64_t;
typedef unsigned long long uintptr_t;

#define BUILD_TOOL "MSVC"
#define COMPILER_VERSION "MSVC"
#endif

typedef int64_t SInt64;
typedef uint64_t UInt64;

/* TODO: validate this */
#define BITMASK(start, end) (~(~0ull << end) << start)

/* should platform config be moved elsewhere? */
/* like, maybe in Xcode's macro configs but then it becomes convoluted */
/* x86_64 is pretty straight forward as all devices have transitioned to UEFI */
/* ^ UPDATE: MHandling this in CMake. */
#if defined (__x86_64__) || defined (_M_AMD64)
#define CURRENT_ARCH "x86_64"
#define PLATFORM_EFI 1 /* ZORMEISTER: x86_64 devices purely use UEFI afaik, should be safe to outright define it here */
#define PLATFORM_SMBIOS 1
#define PLATFORM_ACPI 1
#define PLATFORM_X86 1
#define TARGET_X64 1
#define TARGET_64_ADDRS 1
#endif

#if defined (__i386__) || defined (_M_IX86)
#define CURRENT_ARCH "i386"
#define PLATFORM_EFI 1 /* mmm, a lot of i386 doesn't have UEFI, but who the heck is booting a UEFI file from a legacy based machine anyways? */
#define PLATFORM_SMBIOS 1
#define PLATFORM_ACPI 1
#define PLATFORM_X86 1
#define TARGET_IA32 1
#endif

#if defined (__arm__) || defined (_M_ARM)
#define CURRENT_ARCH "ARM"
#define TARGET_ARM32 1
#endif

#if defined (__arm64__) || defined (_M_ARM64) || defined (__aarch64__)
#define CURRENT_ARCH "ARM64"
#define TARGET_64_ADDRS 1
#define TARGET_ARM64 1
#endif

#if defined (CONFIG_RELEASE)
#define CURRENT_CONFIG "RELEASE"
#endif

/* have the same optimizations as RELEASE but have DEBUG prints */
#if defined (CONFIG_DEVELOPMENT)
#define CURRENT_CONFIG "DEVELOPMENT"
#endif

#if defined (CONFIG_DEBUG)
#define CURRENT_CONFIG "DEBUG"
#endif

#ifndef CURRENT_CONFIG
#define CURRENT_CONFIG "RELEASE"
#define CONFIG_RELEASE 1
#define CONFIG_DEBUG 0
#define CONFIG_DEVELOPMENT 0
#endif

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

#define DBSwapBytes16(bytes) ((bytes & 0xFF00) >> 8) |  ((bytes & 0x00FF << 8))
#define DBSwapBytes32(bytes) ((unsigned int)__builtin_bswap32(bytes))

#endif
