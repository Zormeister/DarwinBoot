// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_DISKIO_H__
#define __PLATFORM_EFI_PROTOCOLS_DISKIO_H__

#include <Platform/EFI/Types.h>

#define EFI_DISK_IO_PROTOCOL_GUID \
    { 0xCE345171, 0xBA0B, 0x11d2, \
        { 0x8e, 0x4F, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } }

extern EFI_GUID gEfiDiskIoProtocolGuid;

#define EFI_DISK_IO_PROTOCOL_REVISION 0x00010000

typedef struct _EFI_DISK_IO_PROTOCOL EFI_DISK_IO_PROTOCOL;

struct _EFI_DISK_IO_PROTOCOL {
    UInt64 Revision;
    EFI_STATUS (*ReadDisk)(EFI_DISK_IO_PROTOCOL *This, UInt32 MediaID, UInt64 Offset, UIntN BufferSize, void *Buffer);
    EFI_STATUS (*WriteDisk)(EFI_DISK_IO_PROTOCOL *This, UInt32 MediaID, UInt64 Offset, UIntN BufferSize, void *Buffer);
};

#define EFI_DISK_IO2_PROTOCOL_GUID \
    { 0x151c8eae, 0x7f2c, 0x472c,  \
        { 0x9e, 0x54, 0x98, 0x28, 0x19, 0x4f, 0x6a, 0x88 } }

extern EFI_GUID gEfiDiskIo2ProtocolGuid;

typedef struct {
    EFI_EVENT Event;
    EFI_STATUS TransactionStatus;
} EFI_DISK_IO2_TOKEN;

#define EFI_DISK_IO2_PROTOCOL_REVISION 0x00020000

typedef struct _EFI_DISK_IO2_PROTOCOL EFI_DISK_IO2_PROTOCOL;

struct _EFI_DISK_IO2_PROTOCOL {
    UInt64 Revision;
    EFI_STATUS (*Cancel)(EFI_DISK_IO2_PROTOCOL *This);
    EFI_STATUS (*ReadDiskEx)(EFI_DISK_IO2_PROTOCOL *This, UInt32 MediaID, UInt64 Offset, EFI_DISK_IO2_TOKEN *Token, UIntN BufferSize, void *Buffer);
    EFI_STATUS (*WriteDiskEx)(EFI_DISK_IO2_PROTOCOL *This, UInt32 MediaID, UInt64 Offset, EFI_DISK_IO2_TOKEN *Token, UIntN BufferSize, void *Buffer);
    EFI_STATUS (*FlushDiskEx)(EFI_DISK_IO2_PROTOCOL *This, EFI_DISK_IO2_TOKEN *Token);
};

#endif /* __PLATFORM_EFI_PROTOCOLS_DISKIO_H__ */
