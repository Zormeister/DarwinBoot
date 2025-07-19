// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/EFI/Protocols/DevicePath.h>
#include <Platform/EFI/Types.h>

#define EFI_LOAD_FILE_PROTOCOL_GUID \
    { 0x56EC3091, 0x954C, 0x11d2,   \
        { 0x8e, 0x3f, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } }

extern EFI_GUID gEfiLoadFileProtocolGuid;

typedef struct _EFI_LOAD_FILE_PROTOCOL EFI_LOAD_FILE_PROTOCOL;

struct _EFI_LOAD_FILE_PROTOCOL {
    EFI_STATUS (*LoadFile)(EFI_LOAD_FILE_PROTOCOL *This, EFI_DEVICE_PATH_PROTOCOL *Path, bool BootPolicy, UIntN *OutBufferSize, void *Buffer);
};

#define EFI_LOAD_FILE2_PROTOCOL_GUID \
    { 0x4006c0c1, 0xfcb3, 0x403e,    \
        { 0x99, 0x6d, 0x4a, 0x6c, 0x87, 0x24, 0xe0, 0x6d } }

extern EFI_GUID gEfiLoadFile2ProtocolGuid;

typedef EFI_LOAD_FILE_PROTOCOL EFI_LOAD_FILE2_PROTOCOL;
