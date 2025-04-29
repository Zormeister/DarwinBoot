// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <Platform/EFI/Types/Address.h>
#include <Platform/EFI/Types/GUID.h>

struct {
    UInt64 Length;
    union {
        EFI_PHYSICAL_ADDRESS DataBlock;
        EFI_PHYSICAL_ADDRESS ContinuationPointer;
    } Union;
} typedef EFI_CAPSULE_BLOCK_DESCRIPTOR;

struct {
    EFI_GUID CapsuleGuid;
    UInt32 HeaderSize;
    UInt32 Flags;
    UInt32 CapsuleImageSize;
} typedef EFI_CAPSULE_HEADER;

#define CAPSULE_FLAGS_PERSIST_ACROSS_RESET 0x00010000
#define CAPSULE_FLAGS_POPULATE_SYSTEM_TABLE 0x00020000
#define CAPSULE_FLAGS_INITIATE_RESET 0x00040000

