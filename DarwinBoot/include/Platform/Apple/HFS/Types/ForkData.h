// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <Platform/Apple/HFS/Types/Extents.h>

struct HFSPlusForkData {
    UInt64 LogicalSize;
    UInt32 ClumpSize;
    UInt32 TotalBlocks;
    HFSPlusExtentRecord Extents;
} typedef HFSPlusForkData;
