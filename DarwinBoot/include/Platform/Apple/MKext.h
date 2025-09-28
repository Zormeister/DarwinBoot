// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_APPLE_MKEXT_H__
#define __PLATFORM_APPLE_MKEXT_H__

#include <Platform/Apple/Mach.h>

/* ah mkexts. the original kext collections. */

/* do note that every field here is stored in big endian. and i mean everything. */

#define kMKextMagic     0x4D4B5854 // 'MKXT'
#define kMKextSignature 0x4D4F5358 // 'MOSX'

#define kMKextVersion1 0x01008000
#define kMKextVersion2 0x02002001

struct {
    UInt32 Magic;
    UInt32 Signature;
    UInt32 Size;
    UInt32 Adler32;
    UInt32 Version;
    UInt32 NumKexts;
    UInt32 CpuType;
    UInt32 CpuSubType;
} typedef MKextHeaderBase;

struct {
    UInt32 Offset;
    UInt32 CompressedSize;
    UInt32 FullSize;
    UInt32 ModifiedTime; /* <libkern/mkext.h> says to use this as a libc time_t */
} typedef MKextFileV1;

struct {
    MKextFileV1 Plist;
    MKextFileV1 Exec;
} typedef MKextEntryV1;

struct {
    MKextHeaderBase Base;
    MKextEntryV1 Kexts[];
} typedef MKextHeaderV1;

struct {
    MKextHeaderBase Base;
    UInt32 PlistOffset;
    UInt32 PlistCompressedSize;
    UInt32 PlistFullSize;
} typedef MKextHeaderV2;

struct {
    UInt32 CompressedSize;
    UInt32 FullSize;
    UInt8 Data[];
} typedef MKextFileV2;

#endif /* __PLATFORM_APPLE_MKEXT_H__ */
