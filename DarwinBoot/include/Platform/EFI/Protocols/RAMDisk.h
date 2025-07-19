// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/EFI/Protocols/DevicePath.h>
#include <Platform/EFI/Types.h>

#define EFI_RAM_DISK_PROTOCOL_GUID \
    { 0xab38a0df, 0x6873, 0x44a9,  \
        { 0x87, 0xe6, 0xd4, 0xeb, 0x56, 0x14, 0x84, 0x49 } }

extern EFI_GUID gEfiRamDiskProtocolGuid;

typedef struct _EFI_RAM_DISK_PROTOCOL EFI_RAM_DISK_PROTOCOL;

struct _EFI_RAM_DISK_PROTOCOL {
    EFI_STATUS (*Register)(UInt64 RamDiskBase, UInt64 RamDiskSize, EFI_GUID *RamDiskType, EFI_DEVICE_PATH_PROTOCOL *ParentDevicePath, EFI_DEVICE_PATH_PROTOCOL **DevicePath);
    EFI_STATUS (*Unregister)(EFI_DEVICE_PATH_PROTOCOL *DevicePath);
};
