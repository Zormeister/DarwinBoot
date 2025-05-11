// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CDBBasicTypes.h>

// Used 
#include <CorePlatform/Board.h>

#if defined (CDB_ARCH_ARM)

#ifndef MAX_CPUS
#define MAX_CPUS 1
#endif

struct {
    const char *CoreName;
    UInt32 PartNumber;
    UInt32 VendorNum;
} typedef CDBARMCPU;

struct _CDBCPUInfo {
    CDBARMCPU CPUs[MAX_CPUS];
};


#endif
