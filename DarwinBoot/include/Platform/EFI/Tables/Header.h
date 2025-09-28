// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_TABLES_HEADER_H__
#define __PLATFORM_EFI_TABLES_HEADER_H__

#include <Platform/EFI/Types.h>

struct _EFI_TABLE_HEADER {
    UInt64 Signature;
    UInt32 Revision;
    UInt32 HeaderSize;
    UInt32 CRC32;
    UInt32 Reserved;
};
typedef struct _EFI_TABLE_HEADER EFI_TABLE_HEADER;

#endif /* __PLATFORM_EFI_TABLES_HEADER_H__ */
