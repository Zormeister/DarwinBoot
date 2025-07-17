// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/Apple/HFS/Types/Catalog.h>

struct {
    UInt16 StartBlock;
    UInt16 BlockCount;
} typedef HFSExtentDescriptor;

struct HFSPlusExtentDescriptor {
    UInt32 StartBlock;
    UInt32 BlockCount;
} typedef HFSPlusExtentDescriptor;

typedef HFSPlusExtentDescriptor HFSPlusExtentRecord[8];

typedef struct {
    UInt8 KeyLength;
    UInt8 ForkType;
    UInt32 FileID;
    UInt16 StartBlock;
} __packed HFSExtentKey;

typedef struct {
    UInt16 KeyLength;
    UInt8 ForkType;
    UInt8 pad;
    HFSCatalogNodeID FileID;
    UInt32 StartBlock;
} __packed HFSPlusExtentKey;

