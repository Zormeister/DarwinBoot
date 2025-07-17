// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <Platform/Apple/HFS/Types/UniStr.h>

typedef UInt32 HFSCatalogNodeID;

enum {
    kHFSRootParentID = 1,
    kHFSRootFolderID = 2,
    kHFSExtentsFileID = 3,
    kHFSCatalogFileID = 4,
    kHFSBadBlockFileID = 5,
    kHFSAllocationFileID = 6,
    kHFSStartupFileID = 7,
    kHFSAttributesFileID = 8,
    kHFSRepairCatalogFileID = 14,
    kHFSBogusExtentFileID = 15,
    kHFSFirstUserCatalogNodeID = 16
};

struct HFSPlusCatalogKey {
    UInt16 KeyLength;
    HFSCatalogNodeID ParentID;
    HFSUniStr255 NodeName;
};
typedef struct HFSPlusCatalogKey HFSPlusCatalogKey;

enum {
    kHFSPlusCatalogMinNodeSize = 4096,
};
