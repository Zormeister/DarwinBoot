// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_APPLE_PRELINKEDKERNEL_H__
#define __PLATFORM_APPLE_PRELINKEDKERNEL_H__

#include <Platform/Apple/Mach.h>

#define kPlatformNameLen 64
#define kRootPathLen     256

#define kPrelinkedKernelPath "/System/Library/PrelinkedKernels/prelinkedkernel"
#define kImmutableKernelPath "/System/Library/PrelinkedKernels/immutablekernel"

enum {
    kPrelinkedKernelCompressionLZVN = 'lzvn',
    kPrelinkedKernelCompressionLZSS = 'lzss',
};

#define kPrelinkedKernelCompressedSignature 'comp'

struct {
    UInt32 Signature;
    UInt32 CompressionType;
    UInt32 Adler32;
    UInt32 UncompressedSize;
    UInt32 CompressedSize;
    UInt32 PrelinkVersion;
    UInt32 Reserved[10];
    char PlatformName[kPlatformNameLen];
    char RootPath[kRootPathLen];
    UInt8 Data[];
} typedef PrelinkedKernelHeader;

/* Mach-O prelinked sections/segment names */
#define kPrelinkTextSegment "__PRELINK_TEXT"
#define kPrelinkTextSection "__text"

#define kPrelinkDataSegment "__PRELINK_DATA"
#define kPrelinkDataSection "__data"

#define kPrelinkInfoSegment "__PRELINK_INFO"
#define kPrelinkInfoSection "__info"

#define kBuiltinInfoSection  "__kmod_info"
#define kBuiltinStartSection "__kmod_start"
#define kBuiltinInitSection  "__kmod_init"
#define kBuildinTermSection  "__kmod_term"

#endif /* __PLATFORM_APPLE_PRELINKEDKERNEL_H__ */
