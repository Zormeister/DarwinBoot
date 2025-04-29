// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/EFI/Types.h>

#define EFI_MEMORY_ATTRIBUTES_TABLE_GUID \
  {0xdcfa911d, 0x26eb, 0x469f, \
    {0xa2, 0x20, 0x38, 0xb7, 0xdc, 0x46, 0x12, 0x20}}

struct {
    UInt32 Version;
    UInt32 NumberOfEntries;
    UInt32 DescriptorSize;
    UInt32 Flags;
    EFI_MEMORY_DESCRIPTOR Descriptors[];
} typedef EFI_MEMORY_ATTRIBUTES_TABLE;

#define EFI_MEMORY_ATTRIBUTES_FLAGS_RT_FORWARD_CONTROL_FLOW_GUARD  0x1

