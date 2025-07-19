// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/EFI/Types.h>

#define EFI_PARTITION_INFO_PROTOCOL_GUID \
    { 0x8cf2f62c, 0xbc9b, 0x4821,        \
        { 0x80, 0x8d, 0xec, 0x9e, 0xc4, 0x21, 0xa1, 0xa0 } }

extern EFI_GUID gEfiPartitionInfoProtocolGuid;

#define EFI_PARTITION_INFO_PROTOCOL_REVISION 0x0001000
#define PARTITION_TYPE_OTHER                 0x00
#define PARTITION_TYPE_MBR                   0x01
#define PARTITION_TYPE_GPT                   0x02

#define EFI_MBR_PARTITION_OSTYPE_SYSTEM_PARTITION 0xEF
#define EFI_MBR_PARTITION_OSTYPE_PMBR             0xEE

/*
 * This header was built for 64-bit architectures.
 *
 * That is to say, I have no idea how a 32-bit environment would handle my code.
 */

typedef struct {
    UInt8 BootIndicator;
    UInt8 StartingCHS[3];
    UInt8 OSType;
    UInt8 EndingCHS[3];
    UInt32 StartingLBA;
    UInt32 EndingLBA;
} __packed EFI_MBR_PARTITION_RECORD;

TYPE_SIZE_CHECK(EFI_MBR_PARTITION_RECORD, 16);

typedef struct {
    char BootCode[440];
    UInt32 UniqueSignature;
    UInt16 Unknown;
    EFI_MBR_PARTITION_RECORD PartitionRecords[4];
    UInt16 Signature;
} __packed EFI_LEGACY_MBR;

TYPE_SIZE_CHECK(EFI_LEGACY_MBR, 512);

#define EFI_GPT_PARTITION_SIG 0x5452415020494645

typedef struct {
    UInt64 Signature;
    UInt32 Revision;
    UInt32 HeaderSize;
    UInt32 HeaderCRC32;
    UInt32 Reserved;
    EFI_LBA MyLBA;
    EFI_LBA AlternateHeaderLBA;
    EFI_LBA FirstUsableLBA;
    EFI_LBA LastUsableLBA;
    EFI_GUID DiskGUID;
    EFI_LBA PartitionEntryLBA;
    UInt32 NumberOfPartitionEntries;
    UInt32 SizeOfPartitionEntry;
    UInt32 PartitionArrayCRC32;
} __packed EFI_GPT_HEADER;

TYPE_SIZE_CHECK(EFI_GPT_HEADER, 92);

typedef struct {
    EFI_GUID PartitionGUID;
    EFI_GUID UniquePartitionGUID;
    EFI_LBA StartingLBA;
    EFI_LBA EndingLBA;
    UInt64 Attributes;
    char PartitionName[72];
} __packed EFI_GPT_PARTITION_ENTRY;

#define EFI_GPT_PARTITION_REQUIRED_PARTITON    0x00000001
#define EFI_GPT_PARTITION_NO_BLOCK_IO          0x00000002
#define EFI_GPT_PARTITION_LEGACY_BIOS_BOOTABLE 0x00000004

TYPE_SIZE_CHECK(EFI_GPT_PARTITION_ENTRY, 128);

typedef struct {
    UInt32 Revision;
    UInt32 Type;
    UInt8 System;
    UInt8 Rsvd[7];
    union {
        EFI_MBR_PARTITION_RECORD MBR;
        EFI_GPT_PARTITION_ENTRY GPT;
    } Info;
} __packed EFI_PARTITION_INFO_PROTOCOL;
