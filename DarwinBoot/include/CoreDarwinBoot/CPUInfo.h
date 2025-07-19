// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

typedef struct _CDBCPUInfo *CDBCPUInfoRef;

enum {
    Unknown = 0,

    /* x86 CPU vendors */
    kCPUVendorIntel = 1,
    kCPUVendorAMD,
    //
    // For AMD CPUs, should I run preflight patches on the kernel?
    // I know that I shouldn't, but for some reason I have the feeling that some
    // idiot will try booting a vanilla kernel on this and open an issue claiming that
    // DarwinBoot is broken.
    //
    // Oh well. If that happens I'll just direct them to this lovely comment.
    //

    /* ARM CPU vendors */
    kCPUVendorARM,
    kCPUVendorAmpere,
    kCPUVendorBroadcom,
    kCPUVendorQualcomm,
    kCPUVendorApple,
    kCPUVendorMotorola,

    /* I genuinely do not have enough patience for an AARCH64 UEFI port. But I won't stop it. */
} typedef CPUVendor;

enum {
    kVMMVendorNotAVMM = 0,

    kVMMVendorQEMU = 1,
    kVMMVendorBhyve,
    kVMMVendorHyperV,
    kVMMVendorVMware,
} typedef VMMVendor;

/*!
  @function CDBCreateCPUInfo
  @abstract Allocates a _CDBCPUInfo instance, which is filled in by the Platform source code.
  @result Returns a CPUInfo handle if the operation was successful
 */
CDBCPUInfoRef CDBCreateCPUInfo(void);

/*!
  @function CDBCPUInfoGetCPUCoreCount
  @abstract Gets the core count from the CPUInfo Ref
  @param CpuInfo The CPUInfo Ref to read from
  @result Returns the number of cores specified from the CPUInfo instance
 */
uint32_t CDBCPUInfoGetCPUCoreCount(CDBCPUInfoRef CpuInfo);

uint32_t CDBCPUInfoGetCPUThreadCount(CDBCPUInfoRef CpuInfo);

CPUVendor CDBCPUInfoGetCPUVendor(CDBCPUInfoRef CpuInfo);

VMMVendor CDBCPUInfoGetVMMVendor(CDBCPUInfoRef CpuInfo);

uint64_t CDBCPUInfoGetTSCFrequency(CDBCPUInfoRef CpuInfo);

uint64_t CDBCPUInfoGetFSBFrequency(CDBCPUInfoRef CpuInfo);
