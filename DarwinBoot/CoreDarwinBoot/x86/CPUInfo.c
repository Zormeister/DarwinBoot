// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CPUInfo.h>
#include <Platform/x86/CPUID.h>

#if TARGET_CPU_X86_64 || TARGET_CPU_I386

/* thank you oh so very much to the people who work on OpenCorePkg and the AMD Vanilla Patches */
typedef enum {
    kCPUIDVendorIntel,
    kCPUIDVendorAMD,
} cpuid_vendor_t;


struct _CDBCPUInfo {
    cpuid_vendor_t vendor;
    uint32_t family;
    uint32_t extfamily;
    uint32_t model;
    uint32_t extmodel;

    uint64_t frequency;
};

#endif
