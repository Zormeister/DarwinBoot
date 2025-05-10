// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

#define FLATTENED_DEVICETREE_MAGIC 0xD00DFEED

struct {
    UInt32 Magic;
    UInt32 TotalSize; /* TODO: VMQEMU should adjust memory ranges to reserve the DT. */
    UInt32 DTStructOffset;
    UInt32 DTStringsOffset;
    UInt32 MemReservationMapOffset;
    UInt32 Version;
    UInt32 LastCompatibleVersion;
    UInt32 BootCPUPhysID;
    UInt32 DTStringsSize;
    UInt32 DTStructureSize;
} typedef FlattenedDTHeader;
