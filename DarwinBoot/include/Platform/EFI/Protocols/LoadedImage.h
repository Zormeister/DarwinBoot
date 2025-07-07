// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/EFI/Types.h>
#include <Platform/EFI/Tables.h>
#include <Platform/EFI/Protocols/DevicePath.h>

#define EFI_LOADED_IMAGE_PROTOCOL_GUID \
  {0x5B1B31A1,0x9562,0x11D2,\
    {0x8E,0x3F,0x00,0xA0,0xC9,0x69,0x72,0x3B}}

#define EFI_LOADED_IMAGE_DEVICE_PATH_PROTOCOL_GUID \
  {0xbc62157e,0x3e33,0x4fec,\
    {0x99,0x20,0x2d,0x3b,0x36,0xd7,0x50,0xdf}}

extern EFI_GUID gEfiLoadedImageProtocolGuid;

extern EFI_GUID gEfiLoadedImageDevicePathProtocolGuid;

#define EFI_LOADED_IMAGE_PROTOCOL_REVISION 0x1000

typedef struct _EFI_LOADED_IMAGE_PROTOCOL EFI_LOADED_IMAGE_PROTOCOL;

struct _EFI_LOADED_IMAGE_PROTOCOL {
    UInt32 Revision;
    EFI_HANDLE ParentHandle;
    EFI_SYSTEM_TABLE *SystemTable;
    EFI_HANDLE DeviceHandle;
    EFI_DEVICE_PATH_PROTOCOL *FilePath;
    void *Rsvd;
    UInt32 LoadOptionsSize;
    void *LoadOptions;
    void *ImageBase;
    UInt64 ImageSize;
    EFI_MEMORY_TYPE ImageCodeType;
    EFI_MEMORY_TYPE ImageDataType;
    EFI_STATUS (*Unload)(EFI_LOADED_IMAGE_PROTOCOL *This);
};
