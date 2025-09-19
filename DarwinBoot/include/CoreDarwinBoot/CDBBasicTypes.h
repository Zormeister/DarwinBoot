// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __COREDARWINBOOT_BASICTYPES__
#define __COREDARWINBOOT_BASICTYPES__

/*!
 * @group Basic Types
 * The name is a little misleading, this header serves as a giga-header for:
 *  - libc/C Standard types
 *  - CPU-related macros
 *  - Non-standard types, eg: uuid_t (and DarwinBoot's guid_t)
 *  - Additionally, it covers macros from <inttypes.h>
 *  - MacTypes (or libkern/IOKit) type names
 *  - BSD-style type names
 *  - Boolean type (_Bool for C17, uses a char for lower C standards, however I have heard about C23)
 */

/*
 * unfun fact: if this header is renamed to fit the naming scheme of the rest of this directory
 * the entire project would break. please do not rename this header to just 'BasicTypes.h' unless
 * you're willing to scour the entire project for header breaks.
 */

#ifdef __cplusplus
    #if __cplusplus < 201703L
        #error This project uses C++ 17, please use C++ 17 for compilation/your LSP
    #endif
#endif
#if defined(__STDC_VERSION__)
    //
    // Context for the !__APPLE__ check is that macOS Catalina doesn't have C17.
    // The way I've rewritten this header though, I don't think it would be impossible to backport
    // DarwinBoot to an earlier C standard.
    //
    #if __STDC_VERSION__ < 201710L && !__APPLE__
        #error This project uses C 17, please use C 17 for compilation/your LSP
    #endif
#endif

//
// can someone explain to me how to get clang-format to NOT skip the typedefs here?
//

// clang-format off
#if defined(__clang__)

    #define BUILD_TOOL             "clang"
    #define COMPILER_VERSION_MAJOR __clang_major__
    #define COMPILER_VERSION_MINOR __clang_minor__
    #define COMPILER_VERSION_PATCH __clang_patchlevel__
    #define COMPILER_VERSION       __VERSION__

    #ifdef __INT8_TYPE__
        typedef __INT8_TYPE__ int8_t;
        #define INT8_C(x)     __INT8_C(x)
        #define INT8_MAX      __INT8_MAX__
        #define PRId8         __INT8_FMTd__
        #define PRIi8         __INT8_FMTi__
    #else
        typedef signed char int16_t;
        #define INT8_C(c)   c
        #define INT8_MAX    127
        #define PRId8       "hhd"
        #define PRIi8       "hhi"
    #endif

    #ifdef __UINT8_TYPE__
        typedef __UINT8_TYPE__ uint8_t;
        #define UINT8_C(x)     __UINT8_C(x)
        #define UINT8_MAX      __UINT8_MAX__
        #define PRIo8          __UINT8_FMTo__
        #define PRIu8          __UINT8_FMTu__
        #define PRIx8          __UINT8_FMTx__
        #define PRIX8          __UINT8_FMTX__
    #else
        typedef unsigned char uint8_t;
        #define UINT8_C(c)    c
        #define UINT8_MAX     255
        #define PRIo8         "hho"
        #define PRIu8         "hhu"
        #define PRIx8         "hhx"
        #define PRIX8         "hhX"
    #endif
    #ifdef __INT16_TYPE__
        typedef __INT16_TYPE__ int16_t;
        #define INT16_C(x)     __INT16_C(x)
        #define INT16_MAX      __INT16_MAX__
        #define PRId16         __INT16_FMTd__
        #define PRIi16         __INT16_FMTi__
    #else
        typedef short int16_t;
        #define INT16_C(c) c
        #define INT16_MAX  32767
        #define PRId16     "hd"
        #define PRIi16     "hi"
    #endif

    #ifdef __UINT16_TYPE__
        typedef __UINT16_TYPE__ uint16_t;
        #define UINT16_C(x)     __UINT16_C(x)
        #define UINT16_MAX      __UINT16_MAX__
        #define PRIo16          __UINT16_FMTo__
        #define PRIu16          __UINT16_FMTu__
        #define PRIx16          __UINT16_FMTx__
        #define PRIX16          __UINT16_FMTX__
    #else
        typedef unsigned short uint16_t;
        #define UINT16_C(c)    c
        #define UINT16_MAX     65535
        #define PRIo16         "ho"
        #define PRIu16         "hu"
        #define PRIx16         "hx"
        #define PRIX16         "hX"
    #endif

    #ifdef __INT32_TYPE__
        typedef __INT32_TYPE__ int32_t;
        #define INT32_C(x)     __INT32_C(x)
        #define INT32_MAX      __INT32_MAX__
        #define PRId32         __INT32_FMTd__
        #define PRIi32         __INT32_FMTi__
    #else
        typedef int int32_t;
        #define INT32_C(c) c
        #define INT32_MAX  2147483647
        #define PRId32     "d"
        #define PRIi32     "i"
    #endif

    #ifdef __UINT32_TYPE__
        typedef __UINT32_TYPE__ uint32_t;
        #define UINT32_C(x)     __UINT32_C(x)
        #define UINT32_MAX      __UINT32_MAX__
        #define PRIo32          __UINT32_FMTo__
        #define PRIu32          __UINT32_FMTu__
        #define PRIx32          __UINT32_FMTx__
        #define PRIX32          __UINT32_FMTX__
    #else
        typedef unsigned int uint32_t;
        #define UINT32_C(c)  c##U
        #define UINT32_MAX   0xFFFFFFFFU
        #define PRIo32       "o"
        #define PRIu32       "u"
        #define PRIx32       "x"
        #define PRIX32       "X"
    #endif

    #ifdef __INT64_TYPE__
        typedef __INT64_TYPE__ int64_t;
        #define INT64_C(x)     __INT64_C(x)
        #define INT64_MAX      __INT64_MAX__
        #define PRId64         __INT64_FMTd__
        #define PRIi64         __INT64_FMTi__
    #else
        typedef long long int int64_t;
        #define INT64_C(c)    c##LL
        #define INT64_MAX     0x7FFFFFFFFFFFFFFFLL
        #define PRId64        "lld"
        #define PRIi64        "lli"
    #endif

    #ifdef __UINT64_TYPE__
        typedef __UINT64_TYPE__ uint64_t;
        #define UINT64_C(x)     __UINT64_C(x)
        #define UINT64_MAX      __UINT64_MAX__
        #define PRIo64          __UINT64_FMTo__
        #define PRIu64          __UINT64_FMTu__
        #define PRIx64          __UINT64_FMTx__
        #define PRIX64          __UINT64_FMTX__
    #else
        typedef long long unsigned int uint64_t;
        #define UINT64_C(c)            c##LL
        #define UINT64_MAX             0xFFFFFFFFFFFFFFFFULL
        #define PRIo64                 "llo"
        #define PRIu64                 "llu"
        #define PRIx64                 "llx"
        #define PRIX64                 "llX"
    #endif

    #ifdef __UINTPTR_TYPE__
        typedef __UINTPTR_TYPE__ uintptr_t;
        #define UINTPTR_MAX      __UINTPTR_MAX__
        #define PRIoPTR          __UINTPTR_FMTo__
        #define PRIuPTR          __UINTPTR_FMTu__
        #define PRIxPTR          __UINTPTR_FMTx__
        #define PRIXPTR          __UINTPTR_FMTX__
    #else
        typedef long long unsigned int uintptr_t;
        #define UINTPTR_MAX            0xFFFFFFFFFFFFFFFFULL
        #define PRIoPTR                "llo"
        #define PRIuPTR                "llu"
        #define PRIxPTR                "llx"
        #define PRIXPTR                "llX"
    #endif

    #ifdef __INTPTR_TYPE__
        typedef __INTPTR_TYPE__ intptr_t;
        #define INTPTR_MAX      __INTPTR_MAX__
        #define PRIdPTR         __INTPTR_FMTd__
        #define PRIiPTR         __INTPTR_FMTi__
    #else
        typedef long long int   intptr_t;
        #define INTPTR_MAX      0x7FFFFFFFFFFFFFFFLL
        #define PRIdPTR         "lld"
        #define PRIiPTR         "lli"
    #endif

    #ifdef __SIZE_TYPE__
        typedef __SIZE_TYPE__ size_t;
        #define SIZE_MAX      __SIZE_MAX__
    #else
        typedef long long unsigned int size_t;
        #define SIZE_MAX               0xFFFFFFFFFFFFFFFFULL
    #endif

    #ifdef __PTRDIFF_TYPE__
        typedef __PTRDIFF_TYPE__ ptrdiff_t;
        #define PTRDIFF_MAX __PTRDIFF_MAX__
    #else
        typedef long long int ptrdiff_t;
        #define PTRDIFF_MAX   0x7FFFFFFFFFFFFFFFLL
    #endif

    #ifdef __INTMAX_TYPE__
        typedef __INTMAX_TYPE__ intmax_t;
        #define INTMAX_C(c)     __INTMAX_C(c)
        #define INTMAX_MAX      __INTMAX_MAX__
        #define PRIdMAX         __INTMAX_FMTd__
        #define PRIiMAX         __INTMAX_FMTi__
    #else
        typedef long long int intmax_t;
        #define INTMAX_C(c)   c##LL
        #define INTMAX_MAX    0x7FFFFFFFFFFFFFFFLL
        #define PRIdMAX       "lld"
        #define PRIiMAX       "lli"
    #endif

    #ifdef __UINTMAX_TYPE__
        typedef __UINTMAX_TYPE__ uintmax_t;
        #define UINTMAX_C(c)     __UINTMAX_C(c)
        #define UINTMAX_MAX      __UINTMAX_MAX__
        #define PRIoMAX          __UINTMAX_FMTo__
        #define PRIuMAX          __UINTMAX_FMTu__
        #define PRIxMAX          __UINTMAX_FMTx__
        #define PRIXMAX          __UINTMAX_FMTX__
    #else
        typedef long long unsigned int uintmax_t;
        #define UINTMAX_C(c)           c #ULL
        #define UINTMAX_MAX            0xFFFFFFFFFFFFFFFFULL
        #define PRIoMAX                "llo"
        #define PRIuMAX                "llu"
        #define PRIxMAX                "llx"
        #define PRIXMAX                "llX"
    #endif

    #if !(__WCHAR_WIDTH__ == 16) && __UEFI__
        #error "Wide strings aren't 16-bits wide whilst we are configured for UEFI, this is bad!"
    #endif

    #ifdef __WCHAR_TYPE__
        #if !__cplusplus
            typedef __WCHAR_TYPE__ wchar_t;
            #define WCHAR_MAX      __WCHAR_MAX__
        #endif
    #else
        #if !__cplusplus
            typedef uint16_t wchar_t;
            #define WCHAR_MAX 65535
        #endif
    #endif

    #define WSTRING(str) u##str

#elif defined(__GNUC__)

/* If for some reason this project is ever built using GCC. */

    #define BUILD_TOOL             "GCC"
    #define COMPILER_VERSION_MAJOR __GNUC__
    #define COMPILER_VERSION_MINOR __GNUC_MINOR__
    #define COMPILER_VERSION_PATCH __GNUC_PATCHLEVEL__
    #define COMPILER_VERSION       __VERSION__

    #ifdef __INT8_TYPE__
        typedef __INT8_TYPE__ int8_t;
        #define INT8_C(x)     __INT8_C(x)
        #define INT8_MAX      __INT8_MAX__
    #else
        typedef signed char int16_t;
        #define INT8_C(c)   c
        #define INT8_MAX    127
    #endif

    #ifdef __UINT8_TYPE__
        typedef __UINT8_TYPE__ uint8_t;
        #define UINT8_C(x)     __UINT8_C(x)
        #define UINT8_MAX      __UINT8_MAX__
    #else
        typedef unsigned char uint8_t;
        #define UINT8_C(c)    c
        #define UINT8_MAX     255
    #endif

    #define PRId8 "hhd"
    #define PRIi8 "hhi"
    #define PRIo8 "hho"
    #define PRIu8 "hhu"
    #define PRIx8 "hhx"
    #define PRIX8 "hhX"

    #ifdef __INT16_TYPE__
        typedef __INT16_TYPE__ int16_t;
        #define INT16_C(x)     __INT16_C(x)
        #define INT16_MAX      __INT16_MAX__
    #else
        typedef short int int16_t;
        #define INT16_C(c) c
        #define INT16_MAX  32767
    #endif

    #ifdef __UINT16_TYPE__
        typedef __UINT16_TYPE__ uint16_t;
        #define UINT16_C(x)     __UINT16_C(x)
        #define UINT16_MAX      __UINT16_MAX__
    #else
        typedef unsigned short int uint16_t;
        #define UINT16_C(c)        c
        #define UINT16_MAX         65535
    #endif

    #define PRId16 "hd"
    #define PRIi16 "hi"
    #define PRIo16 "ho"
    #define PRIu16 "hu"
    #define PRIx16 "hx"
    #define PRIX16 "hX"

    #ifdef __INT32_TYPE__
        typedef __INT32_TYPE__ int32_t;
        #define INT32_C(x)     __INT32_C(x)
        #define INT32_MAX      __INT32_MAX__
    #else
        typedef int int32_t;
        #define INT32_C(c) c
        #define INT32_MAX  2147483647
    #endif

    #ifdef __UINT32_TYPE__
        typedef __UINT32_TYPE__ uint32_t;
        #define UINT32_C(x)     __UINT32_C(x)
        #define UINT32_MAX      __UINT32_MAX__
    #else
        typedef unsigned int uint32_t;
        #define UINT32_C(c)  c##U
        #define UINT32_MAX   0xFFFFFFFFU
    #endif

    #define PRId32 "d"
    #define PRIi32 "i"
    #define PRIo32 "o"
    #define PRIu32 "u"
    #define PRIx32 "x"
    #define PRIX32 "X"

    #ifdef __INT64_TYPE__
        typedef __INT64_TYPE__ int64_t;
        #define INT64_C(x)     __INT64_C(x)
        #define INT64_MAX      __INT64_MAX__
    #else
        typedef long int int64_t;
        #define INT64_C(c) c##LL
        #define INT64_MAX  0x7FFFFFFFFFFFFFFFL
    #endif

    #ifdef __UINT64_TYPE__
        typedef __UINT64_TYPE__ uint64_t;
        #define UINT64_C(x)     __UINT64_C(x)
        #define UINT64_MAX      __UINT64_MAX__
    #else
        typedef long unsigned int uint64_t;
        #define UINT64_C(c)       c##LL
        #define UINT64_MAX        0xFFFFFFFFFFFFFFFFUL
    #endif

    #define PRId64 "ld"
    #define PRIi64 "li"
    #define PRIo64 "lo"
    #define PRIu64 "lu"
    #define PRIx64 "lx"
    #define PRIX64 "lX"

    #ifdef __UINTPTR_TYPE__
        typedef __UINTPTR_TYPE__ uintptr_t;
        #define UINTPTR_MAX      __UINTPTR_MAX__
    #else
        typedef long unsigned int uintptr_t;
        #define UINTPTR_MAX       0xFFFFFFFFFFFFFFFFUL
    #endif

    #ifdef __INTPTR_TYPE__
        typedef __INTPTR_TYPE__ intptr_t;
        #define INTPTR_MAX      __INTPTR_MAX__
    #else
        typedef long int intptr_t;
        #define INTPTR_MAX 0x7FFFFFFFFFFFFFFFL
    #endif

    #define PRIdPTR "ld"
    #define PRIiPTR "li"
    #define PRIoPTR "lo"
    #define PRIuPTR "lu"
    #define PRIxPTR "lx"
    #define PRIXPTR "lX"

    #ifdef __SIZE_TYPE__
        typedef __SIZE_TYPE__ size_t;
        #define SIZE_MAX      __SIZE_MAX__
    #else
        typedef long unsigned int size_t;
        #define SIZE_MAX          0xFFFFFFFFFFFFFFFFUL
    #endif

    #ifdef __PTRDIFF_TYPE__
        typedef __PTRDIFF_TYPE__ ptrdiff_t;
        #define PTRDIFF_MAX      __PTRDIFF_MAX__
    #else
        typedef long int ptrdiff_t;
        #define PTRDIFF_MAX 0x7FFFFFFFFFFFFFFFL
    #endif

    #ifdef __INTMAX_TYPE__
        typedef __INTMAX_TYPE__ intmax_t;
        #define INTMAX_C(c)     __INTMAX_C(c)
        #define INTMAX_MAX      __INTMAX_MAX__
    #else
        typedef long int intmax_t;
        #define INTMAX_C(c) c##LL
        #define INTMAX_MAX  0x7FFFFFFFFFFFFFFFL
    #endif

    #ifdef __UINTMAX_TYPE__
        typedef __UINTMAX_TYPE__ uintmax_t;
        #define UINTMAX_C(c)     __UINTMAX_C(c)
        #define UINTMAX_MAX      __UINTMAX_MAX__
    #else
        typedef long unsigned int uintmax_t;
        #define UINTMAX_C(c)      c##UL
        #define UINTMAX_MAX       0xFFFFFFFFFFFFFFFFUL
    #endif

    #define PRIdMAX "ld"
    #define PRIiMAX "li"
    #define PRIoMAX "lo"
    #define PRIuMAX "lu"
    #define PRIxMAX "lx"
    #define PRIXMAX "lX"

    #if !(__WCHAR_WIDTH__ == 16) && UEFI
        #error "Wide strings aren't 16-bits wide whilst we are configured for UEFI, this is bad!"
    #endif

    #ifdef __WCHAR_TYPE__
        #if !__cplusplus
            typedef __WCHAR_TYPE__ wchar_t;
            #define WCHAR_MAX      __WCHAR_MAX__
        #endif
    #else
        #if !__cplusplus
            typedef uint16_t wchar_t;
            #define WCHAR_MAX 65535
        #endif
    #endif

    #define WSTRING(str) L##str

#endif

/* MacTypes, also the libkern types from XNU. */
typedef int8_t SInt8;
typedef int16_t SInt16;
typedef int32_t SInt32;
typedef int64_t SInt64;
typedef uint8_t UInt8;
typedef uint16_t UInt16;
typedef uint32_t UInt32;
typedef uint64_t UInt64;

/* BSD types? Not sure what these are actually called. */
typedef uint8_t u_int8_t;
typedef uint16_t u_int16_t;
typedef uint32_t u_int32_t;
typedef uint64_t u_int64_t;

#define NULL (void *)0

#if (__STDC_VERSION__ >= 202311)

    //
    // C23 defines a boolean type, thus we don't need to do anything.
    //

#elif (__STDC_VERSION__ >= 201710L)

    /* Use C17's boolean type. */
    typedef _Bool bool;
    #define true  1
    #define false 0

#elif !__cplusplus

    /* Otherwise just treat it like a char. */
    typedef char bool;
    #define true  1
    #define false 0

#endif

#define __packed __attribute__((packed))
#define PACKED   __packed

#define __db_type_must_be_of_size(type, size) _Static_assert(sizeof(type) == size, #type " is not of the correct size.")

/* Better name for this macro? */
#define STRUCT_SIZE_CHECK(type, size) __db_type_must_be_of_size(struct type, size)
#define TYPE_SIZE_CHECK(type, size)   __db_type_must_be_of_size(type, size)

#if __cplusplus
#define __BEGIN_DECLS extern "C" {
#define __END_DECLS }
#else
#define __BEGIN_DECLS
#define __END_DECLS
#endif

/* This is to account for the fact C++ is now supported in the project. */
#define CDB_API_BEGIN __BEGIN_DECLS
#define CDB_API_END __END_DECLS

// clang-format on

//
// We don't rely on __has_target_os or other related stuff.
//
#if __has_builtin(__is_target_arch)
    #if __is_target_arch(arm)
        #define TARGET_CPU_ARM    1
        #define TARGET_CPU_ARM64  0
        #define TARGET_CPU_I386   0
        #define TARGET_CPU_X86_64 0
        #define TARGET_CPU_STRING "ARM"
        #define TARGET_CPU_ADDRESS_SIZE 32
    #elif __is_target_arch(arm64) || __is_target_arch(arm64e) || __is_target_arch(arm64_32)
        #define TARGET_CPU_ARM    0
        #define TARGET_CPU_ARM64  1
        #define TARGET_CPU_I386   0
        #define TARGET_CPU_X86_64 0
        #define TARGET_CPU_STRING "ARM64"

        //
        // arm64_32 is ARM64, but with 32-bit pointers.
        //
        #if __is_target_arch(arm64_32)
            #define TARGET_CPU_ADDRESS_SIZE 32
        #else
            #define TARGET_CPU_ADDRESS_SIZE 64
        #endif
    #elif __is_target_arch(i386)
        #define TARGET_CPU_ARM    0
        #define TARGET_CPU_ARM64  0
        #define TARGET_CPU_I386   1
        #define TARGET_CPU_X86_64 0
        #define TARGET_CPU_STRING "i386"
        #define TARGET_CPU_ADDRESS_SIZE 32
    #elif __is_target_arch(x86_64)
        #define TARGET_CPU_ARM    0
        #define TARGET_CPU_ARM64  0
        #define TARGET_CPU_I386   0
        #define TARGET_CPU_X86_64 1
        #define TARGET_CPU_STRING "x86_64"
        #define TARGET_CPU_ADDRESS_SIZE 64
    #endif
#else
    //
    // If that isn't available, use the old fashioned method.
    //
    #if defined(__arm__) || defined(_M_ARM)
        #define TARGET_CPU_ARM    1
        #define TARGET_CPU_ARM64  0
        #define TARGET_CPU_I386   0
        #define TARGET_CPU_X86_64 0
        #define TARGET_CPU_STRING "ARM"
    #elif defined(__arm64__) || defined(_M_ARM64) || defined(__aarch64__)
        #define TARGET_CPU_ARM    0
        #define TARGET_CPU_ARM64  1
        #define TARGET_CPU_I386   0
        #define TARGET_CPU_X86_64 0
        #define TARGET_CPU_STRING "ARM64"
    #elif defined(__i386__) || defined(_M_IX86)
        #define TARGET_CPU_ARM    0
        #define TARGET_CPU_ARM64  0
        #define TARGET_CPU_I386   1
        #define TARGET_CPU_X86_64 0
        #define TARGET_CPU_STRING "i386"
    #elif defined(__x86_64__) || defined(_M_AMD64)
        #define TARGET_CPU_ARM    0
        #define TARGET_CPU_ARM64  0
        #define TARGET_CPU_I386   0
        #define TARGET_CPU_X86_64 1
        #define TARGET_CPU_STRING "x86_64"
    #endif
#endif

#if TARGET_CPU_X86_64 || TARGET_CPU_ARM64
    typedef UInt64 UIntN;
#else
    typedef UInt32 UIntN;
#endif

#pragma mark - Target feature macros

#ifndef CURRENT_CONFIG
    #define CONFIG_RELEASE     1
    #define CONFIG_DEBUG       0
    #define CONFIG_DEVELOPMENT 0
#endif

#if defined(CONFIG_RELEASE) && CONFIG_RELEASE == 1
    #define CURRENT_CONFIG "RELEASE"
    #define RELEASE        1
#endif

/* have the same optimizations as RELEASE but have DEBUG prints */
#if defined(CONFIG_DEVELOPMENT) && CONFIG_DEVELOPMENT == 1
    #define CURRENT_CONFIG "DEVELOPMENT"
    #define DEVELOPMENT    1
#endif

#if defined(CONFIG_DEBUG) && CONFIG_DEBUG == 1
    #define CURRENT_CONFIG "DEBUG"
    #define DEBUG          1
#endif

#pragma mark - Non-Standard Types

/* This mirrors the definition of a GUID in UEFI. */
typedef struct {
    UInt32 Data1;
    UInt16 Data2;
    UInt16 Data3;
    UInt8 Data4[8];
} guid_t;

typedef uint8_t uuid_t[16];

#if TARGET_CPU_ADDRESS_SIZE == 64
typedef uint64_t virtual_address_t;
typedef uint64_t physical_address_t;
#elif TARGET_CPU_ADDRESS_SIZE == 32
typedef uint32_t virtual_address_t;
typedef uint32_t physical_address_t;
#else
#error "Unsupported CPU address size."
#endif

typedef virtual_address_t CDBVirtualAddress;
typedef physical_address_t CDBPhysicalAddress;

#pragma mark - Built-in Macros and Types

/* Quickly check for these macros */
#ifndef __has_builtin
    #define __has_builtin(x) 0
#endif

#ifndef __has_attribute
    #define __has_attribute(x) 0
#endif

#if __has_attribute(__counted_by__)
    #define __counted_by(member) __attribute__((__counted_by__(member)))
#else
    #define __counted_by(member)
#endif

/* If we have the builtins; define them here */

#if __has_builtin(__builtin_bswap16)
    #define bswap16(x) __builtin_bswap16(x)
#else
    #define bswap16(x) (x & 0x00FF) << 4 | (x & 0xFF00) >> 4
#endif

#if __has_builtin(__builtin_bswap32)
    #define bswap32(x) __builtin_bswap32(x)
#endif

#if __has_builtin(__builtin_bswap64)
    #define bswap64(x) __builtin_bswap64(x)
#endif

#if __DARWINBOOT_CXX_REARCH__
#define COREPLATFORM_CXX 1
#endif

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

    #define OSSwapBigToHostInt16(x) bswap16(x)
    #define OSSwapBigToHostInt32(x) bswap32(x)
    #define OSSwapBigToHostInt64(x) bswap64(x)

    #define OSSwapHostToBigInt16(x) bswap16(x)
    #define OSSwapHostToBigInt32(x) bswap32(x)
    #define OSSwapHostToBigInt64(x) bswap64(x)

    #define OSSwapHostToLittleInt16(x) x
    #define OSSwapHostToLittleInt32(x) x
    #define OSSwapHostToLittleInt64(x) x

    #define OSSwapLittleToHostInt16(x) x
    #define OSSwapLittleToHostInt32(x) x
    #define OSSwapLittleToHostInt64(x) x

#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

    #define OSSwapBigToHostInt16(x) x
    #define OSSwapBigToHostInt32(x) x
    #define OSSwapBigToHostInt64(x) x

    #define OSSwapHostToBigInt16(x) x
    #define OSSwapHostToBigInt32(x) x
    #define OSSwapHostToBigInt64(x) x

    #define OSSwapHostToLittleInt16(x) bswap16(x)
    #define OSSwapHostToLittleInt32(x) bswap32(x)
    #define OSSwapHostToLittleInt64(x) bswap64(x)

    #define OSSwapLittleToHostInt16(x) bswap16(x)
    #define OSSwapLittleToHostInt32(x) bswap32(x)
    #define OSSwapLittleToHostInt64(x) bswap64(x)

#endif

/*! 
 * @define CDB_OBJECT_DEFINE
 * The macro to define a CoreDarwinBoot object.
 */
#define CDB_OBJECT_DEFINE(obj) typedef struct _CDB##obj *CDB##obj##Ref

#if __cplusplus
    #define CDB_EXPORT extern "C"
#else
    #define CDB_EXPORT extern
#endif

#endif /* __COREDARWINBOOT_BASICTYPES__ */
