// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_SIMPLEFILESYSTEM_H__
#define __PLATFORM_EFI_PROTOCOLS_SIMPLEFILESYSTEM_H__

#include <Platform/EFI/Protocols/File.h>

#define EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID \
    { 0x0964e5b22, 0x6459, 0x11d2,           \
        { 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } }

extern EFI_GUID gEfiSimpleFileSystemProtocolGuid;

#define EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_REVISION 0x00010000

typedef struct _EFI_SIMPLE_FILE_SYSTEM_PROTOCOL EFI_SIMPLE_FILE_SYSTEM_PROTOCOL;

struct _EFI_SIMPLE_FILE_SYSTEM_PROTOCOL {
    UInt64 Revision;

    EFI_STATUS (*OpenVolume)(EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *This, EFI_FILE_PROTOCOL **Root);
};

#endif /* __PLATFORM_EFI_PROTOCOLS_SIMPLEFILESYSTEM_H__ */
