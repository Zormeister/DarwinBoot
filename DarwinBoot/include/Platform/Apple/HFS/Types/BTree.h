// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

enum {
    kBTLeafNode = -1,
    kBTIndexNode = 0,
    kBTHeaderNode = 1,
    kBTMapNode = 2
};

typedef struct {
    UInt32 FLink; /* forwards */
    UInt32 BLink; /* backwards */
    SInt8 Kind;
    UInt8 Height;
    UInt16 NumRecords;
    UInt16 Reserved;
} __packed BTNodeDescriptor;

TYPE_SIZE_CHECK(BTNodeDescriptor, 14);


typedef struct {
    UInt16 TreeDepth;
    UInt32 RootNode;
    UInt32 LeafRecords;
    UInt32 FirstLeafNode;
    UInt32 LastLeafNode;
    UInt16 NodeSize;
    UInt16 MaxKeyLength;
    UInt32 TotalNodes;
    UInt32 FreeNodes;
    UInt16 Reserved1;
    UInt32 ClumpSize;
    UInt8 BTreeType;
    UInt8 KeyCompareType;
    UInt32 Attributes;
    UInt32 Reserved2[16];
} __packed BTHeaderRec;

enum {
    kHFSBTreeType = 0,
    kUserBTreeType = 128,
    kReservedBTreeType = 255
};

enum {
    kHFSBinaryCompare = 0xBC,
    kHFSCaseFolding = 0xCF,
};

enum {
    kBTBadCloseMask = 0x1,
    kBTBigKeysMask = 0x2,
    kBTVariableIndexKeysMask = 0x4
};
