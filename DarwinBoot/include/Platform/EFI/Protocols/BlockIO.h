// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/EFI/Types.h>

#define EFI_BLOCK_IO_PROTOCOL_GUID \
   {0x964e5b21,0x6459,0x11d2,\
    {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

extern EFI_GUID gEfiBlockIoProtocolGuid;

#define EFI_BLOCK_IO_PROTOCOL_REVISION2   0x00020001
#define EFI_BLOCK_IO_PROTOCOL_REVISION3   ((2<<16) | (31))

struct {
    UInt32 MediaID;
    bool IsRemoveable;
    bool IsPresent;
    bool IsLogicalPartition;
    bool IsReadOnly;
    bool IsWriteCaching;
    UInt32 BlockSize;
    UInt32 IOAlignment;
    EFI_LBA LastBlock;

    /* Revision 2 data */
    EFI_LBA LowestAlignedLBA;
    UInt32 LogicalPerPhysicalBlocks;

    /* Revision 3 data */
    UInt32 OptimalTransferLengthGranularity;
} typedef EFI_BLOCK_IO_MEDIA;

typedef struct _EFI_BLOCK_IO_PROTOCOL EFI_BLOCK_IO_PROTOCOL;

struct _EFI_BLOCK_IO_PROTOCOL {
    UInt64 Revision;
    EFI_BLOCK_IO_MEDIA *Media;

    EFI_STATUS (*Reset)(EFI_BLOCK_IO_PROTOCOL *This, bool ExtendedVerification);
    EFI_STATUS (*ReadBlocks)(EFI_BLOCK_IO_PROTOCOL *This, UInt32 MediaID, EFI_LBA LBA, UIntN BufferSize, void *Buffer);
    EFI_STATUS (*WriteBlocks)(EFI_BLOCK_IO_PROTOCOL *This, UInt32 MediaID, EFI_LBA LBA, UIntN BufferSize, void *Buffer);
    EFI_STATUS (*FlushAllBlocks)(EFI_BLOCK_IO_PROTOCOL *This);
};

/* Block I/O 2 stuff */

#define EFI_BLOCK_IO2_PROTOCOL_GUID \
   {0xa77b2472,0xe282,0x4e9f, \
    {0xa2,0x45,0xc2,0xc0,0xe2,0x7b,0xbc,0xc1}}

extern EFI_GUID gEfiBlockIo2ProtocolGuid;

struct {
    EFI_EVENT Event;
    EFI_STATUS TransactionStatus;
} typedef EFI_BLOCK_IO2_TOKEN;

typedef struct _EFI_BLOCK_IO2_PROTOCOL EFI_BLOCK_IO2_PROTOCOL;

struct _EFI_BLOCK_IO2_PROTOCOL {
    EFI_BLOCK_IO_MEDIA *Media;

    EFI_STATUS (*Reset)(EFI_BLOCK_IO2_PROTOCOL *This, bool ExtendedVerification);
    EFI_STATUS (*ReadBlocks)(EFI_BLOCK_IO2_PROTOCOL *This, UInt32 MediaID, EFI_LBA LBA, EFI_BLOCK_IO2_TOKEN *Token, UIntN BufferSize, void *Buffer);
    EFI_STATUS (*WriteBlocks)(EFI_BLOCK_IO2_PROTOCOL *This, UInt32 MediaID, EFI_LBA LBA, EFI_BLOCK_IO2_TOKEN * Token, UIntN BufferSize, void *Buffer);
    EFI_STATUS (*FlushAllBlocks)(EFI_BLOCK_IO2_PROTOCOL *This, EFI_BLOCK_IO2_TOKEN *Token);
};
