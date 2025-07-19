// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

struct HFSPlusBSDInfo {
    UInt32 OwnerID;
    UInt32 GroupID;
    UInt8 AdminFlags;
    UInt8 OwnerFlags;
    UInt16 FileMode;
    union {
        UInt32 INodeNumber;
        UInt32 LinkCount;
        UInt32 RawDevice;
    } Special;
} typedef HFSPlusBSDInfo;

#define HFS_SF_ARCHIVED  0x01
#define HFS_SF_IMMUTABLE 0x02
#define HFS_SF_APPEND    0x04

#define HFS_UF_NODUMP    0x01
#define HFS_UF_IMMUTABLE 0x02
#define HFS_UF_APPEND    0x04
#define HFS_UF_OPAQUE    0x08

#define HFS_S_IFREG  0x8000
#define HFS_S_IFLNK  0xA000
#define HFS_S_IFSOCK 0xC000
#define HFS_S_IFWHT  0xE000
#define HFS_S_IFMT   0xF000

#define HFS_S_IFIFO 0x1000
#define HFS_S_IFCHR 0x2000
#define HFS_S_IFDIR 0x4000
#define HFS_S_IFBLK 0x6000

#define HFS_S_ISUID 0x800
#define HFS_S_ISGID 0x400
#define HFS_S_ISTXT 0x200

#define HFS_S_IRWXU 0x1C0
#define HFS_S_IRUSR 0x100
#define HFS_S_IWUSR 0x80
#define HFS_S_IXUSR 0x40

#define HFS_S_IRWXG 0x38
#define HFS_S_IRGRP 0x20
#define HFS_S_IWGRP 0x10
#define HFS_S_IXGRP 0x8

#define HFS_S_IRWXO 0x7
#define HFS_S_IROTH 0x4
#define HFS_S_IWOTH 0x2
#define HFS_S_IXOTH 0x1
