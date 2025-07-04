// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include "CoreDarwinBoot/CDBBasicTypes.h"
#include "Platform/EFI/Types/Status.h"
#include <Platform/EFI/Types.h>

typedef struct {
    EFI_EVENT Event;
    EFI_STATUS Status;
    UIntN BufferSize;
    void *Buffer;
} EFI_FILE_IO_TOKEN;

#define EFI_FILE_PROTOCOL_REVISION 0x00010000
#define EFI_FILE_PROTOCOL_REVISION2 0x00020000
#define EFI_FILE_PROTOCOL_LATEST_REVISION EFI_FILE_PROTOCOL_REVISION2

typedef struct _EFI_FILE_PROTOCOL EFI_FILE_PROTOCOL;

struct _EFI_FILE_PROTOCOL {
    UInt64 Revision;

    EFI_STATUS (*Open)(EFI_FILE_PROTOCOL *This, EFI_FILE_PROTOCOL **NewHandle, wchar_t *FileName, UInt64 Mode, UInt64 Attributes);
    EFI_STATUS (*Close)(EFI_FILE_PROTOCOL *This);
    EFI_STATUS (*Delete)(EFI_FILE_PROTOCOL *This);
    EFI_STATUS (*Read)(EFI_FILE_PROTOCOL *This, UIntN *BufferSize, void *Buffer);
    EFI_STATUS (*Write)(EFI_FILE_PROTOCOL *This, UIntN *BufferSize, void *Buffer);
    EFI_STATUS (*GetPosition)(EFI_FILE_PROTOCOL *This, UInt64 *Position);
    EFI_STATUS (*SetPosition)(EFI_FILE_PROTOCOL *This, UInt64 Position);
    EFI_STATUS (*GetInfo)(EFI_FILE_PROTOCOL *This, EFI_GUID *InformationType, UIntN *BufferSize, void *Buffer);
    EFI_STATUS (*SetInfo)(EFI_FILE_PROTOCOL *This, EFI_GUID *InformationType, UIntN BufferSize, void *Buffer);
    EFI_STATUS (*Flush)(EFI_FILE_PROTOCOL *This);

    /* Revision 2 functions. */
    EFI_STATUS (*OpenEx)(EFI_FILE_PROTOCOL *This, EFI_FILE_PROTOCOL **NewHandle, wchar_t *FileName, UInt64 Mode, UInt64 Attributes, EFI_FILE_IO_TOKEN *Token);
    EFI_STATUS (*ReadEx)(EFI_FILE_PROTOCOL *This, EFI_FILE_IO_TOKEN *Token);
    EFI_STATUS (*WriteEx)(EFI_FILE_PROTOCOL *This, EFI_FILE_IO_TOKEN *Token);
    EFI_STATUS (*FlushEx)(EFI_FILE_PROTOCOL *This, EFI_FILE_IO_TOKEN *Token);
};

enum {
    EFI_FILE_MODE_READ = 0x1,
    EFI_FILE_MODE_WRITE = 0x2,
    EFI_FILE_MODE_CREATE = 0x8000000000000000,
};

enum {
    EFI_FILE_READ_ONLY = 0x1,
    EFI_FILE_HIDDEN = 0x2,
    EFI_FILE_SYSTEM = 0x4,
    EFI_FILE_RESERVED = 0x8,
    EFI_FILE_DIRECTORY = 0x10,
    EFI_FILE_ARCHIVE = 0x20,
    EFI_FILE_VALID_ATTR = 0x37,
};

#define EFI_FILE_INFO_ID \
   {0x09576e92,0x6d3f,0x11d2,\
    {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

struct {
    UInt64 Size;
    UInt64 FileSize;
    UInt64 PhysicalSize;
    EFI_TIME CreateTime;
    EFI_TIME LastAccessTime;
    EFI_TIME ModificationTime;
    UInt64 Attributes;
    wchar_t FileName[];
} typedef EFI_FILE_INFO;


#define EFI_FILE_SYSTEM_INFO_ID \
   {0x09576e93,0x6d3f,0x11d2, \
    {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

struct {
    UInt64 Size;
    bool ReadOnly;
    UInt64 VolumeSize;
    UInt64 FreeSpace;
    UInt32 BlockSize;
    wchar_t VolumeName[];
} typedef EFI_FILE_SYSTEM_INFO;


#define EFI_FILE_SYSTEM_VOLUME_LABEL_ID \
   {0xdb47d7d3,0xfe81,0x11d3,0x9a35,\
    {0x00,0x90,0x27,0x3f,0xC1,0x4d}}

struct {
    wchar_t VolumeName[];
} typedef EFI_FILE_SYSTEM_VOLUME_LABEL;

