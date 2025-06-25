// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

typedef struct _CDBCPUInfo *CDBCPUInfoHandle;

enum CPUVendor {
    Unknown = 0,
    #if defined (__x86_64__) || defined (__x86_64__)
    /* should i even add VIA x86 support here */
    Intel,
    AMD,
    #endif
    /* ARM platform port? IE: ARM w/ no UEFI. */
    /* UEFI ARM? */
    #if defined (__arm__) || defined (__arm64__)
    ARM, /* Generic */
    Ampere,
    Broadcom,
    Qualcomm,
    Apple,
    Motorola,
    #endif
};

enum VMMVendor {
    NoVMM,
    QEMU,
    Bhyve,
    HyperV,
    VMware,
};

/*!
  @function CDBCreateCPUInfo
  @abstract Allocates a _CDBCPUInfo instance, which is filled in by the Platform source code.
  @result Returns a CPUInfo handle if the operation was successful
 */
CDBCPUInfoHandle CDBCreateCPUInfo(void);

/*!
  @function CDBCPUInfoGetCPUCoreCount
  @abstract Gets the core count from the CPUInfo handle 
  @param CpuInfo The CPUInfo handle to read from
  @result Returns the number of cores specified from the CPUInfo instance
 */
uint32_t CDBCPUInfoGetCPUCoreCount(CDBCPUInfoHandle CpuInfo);

uint32_t CDBCPUInfoGetCPUThreadCount(CDBCPUInfoHandle CpuInfo);

enum CPUVendor CDBCPUInfoGetCPUVendor(CDBCPUInfoHandle CpuInfo);

enum VMMVendor CDBCPUInfoGetVMMVendor(CDBCPUInfoHandle CpuInfo);

uint64_t CDBCPUInfoGetTSCFrequency(CDBCPUInfoHandle CpuInfo);

uint64_t CDBCPUInfoGetFSBFrequency(CDBCPUInfoHandle CpuInfo);
