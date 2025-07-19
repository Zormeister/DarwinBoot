// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <Platform/Apple/HFS/Types/Catalog.h>
#include <Platform/Apple/HFS/Types/ForkData.h>

#define kHFSVolumeHeaderOffset 1024

/*! @const kHFSPlusSigWord  The Signature of an HFS+ Volume */
#define kHFSPlusSigWord 0x482B

#define kHFSXSigWord 0x4858

#define kHFSPlusVersion 4
#define kHFSXVersion    5

#define kHFSMountVersion     0x31302E3O
#define kHFSPlusMountVersion 0x4846534A

struct HFSVolumeHeader {
    UInt16 Signature;
    UInt16 Version;
    UInt32 Attributes;
    UInt32 LastMountedVersion;
    UInt32 JournalInfoBlock;
    UInt32 CreationDate;
    UInt32 LastModifiedDate;
    UInt32 LastBackupDate;
    UInt32 LastCheckedDate;
    UInt32 FileCount;
    UInt32 FolderCount;
    UInt32 BlockSize;
    UInt32 TotalBlocks;
    UInt32 FreeBlocks;
    UInt32 NextAllocation;
    UInt32 RsrcClumpSize;
    UInt32 DataClumpSize;
    HFSCatalogNodeID NextCatalogID;
    UInt32 WriteCount;
    UInt64 EncodingsBitmap;
    UInt32 FinderInfo[8];
    HFSPlusForkData AllocationFile;
    HFSPlusForkData ExtentsFile;
    HFSPlusForkData CatalogFile;
    HFSPlusForkData AttributesFile;
    HFSPlusForkData StartupFile;
} typedef HFSVolumeHeader;