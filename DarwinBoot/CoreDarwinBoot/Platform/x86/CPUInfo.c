// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CPUInfo.h>

/* thank you oh so very much to the people who work on OpenCorePkg and the AMD Vanilla Patches */

#if TARGET_X64

struct _CDBCPUInfo {
    enum CPUVendor vendor;
    enum VMMVendor vmm;
    bool IsVMM;
    UInt32 CoreCount;
    UInt32 ThreadCount;
    UInt32 FSBFrequency;
    UInt32 TSCFrequency;
    bool UsesHSATopology;
};

#endif
