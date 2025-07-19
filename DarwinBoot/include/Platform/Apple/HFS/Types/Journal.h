// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

struct {
    UInt32 Flags;
    UInt32 DeviceSignature[8];
    UInt64 Offset;
    UInt64 Size;
    UInt32 Reserved[32];    
} __packed typedef HFSJournalInfoBlock;

