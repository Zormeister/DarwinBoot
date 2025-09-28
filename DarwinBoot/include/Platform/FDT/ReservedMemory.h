// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_FDT_RESERVEDMEMORY_H__
#define __PLATFORM_FDT_RESERVEDMEMORY_H__

#include <CoreDarwinBoot/CDBBasicTypes.h>

struct {
    UInt64 Base;
    UInt64 Size;
} typedef FlattenedDTReservedMemoryEntry;

#endif /* __PLATFORM_FDT_RESERVEDMEMORY_H__ */
