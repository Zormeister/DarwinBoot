// Copyright © 2024 Zormeister. All rights reserved.

/*
 * This file is part of DarwinBoot.
 
 * DarwinBoot is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 
 * DarwinBoot is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License along with DarwinBoot. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once
#include "CDBBasicTypes.h"

typedef struct _CDBCPUInfo *CDBCPUInfoHandle;

enum CPUVendor {
    #if TARGET_X64 || TARGET_IA32
    /* should i even add VIA x86 support here */
    Intel,
    AMD,
    #endif
    /* ARM platform port? IE: ARM w/ no UEFI. */
    /* UEFI ARM? */
    #if TARGET_ARM32 || TARGET_ARM64
    ARM, /* Generic */
    Ampere,
    Broadcom,
    Qualcomm,
    #endif
};

enum VMMVendor {
    NoVMM,
    QEMU,
    Bhyve,
    HyperV,
    VMware,
};

CDBCPUInfoHandle CDBCreateCPUInfo(void);

/* CPU core count */
uint32_t CDBCPUInfoGetCPUCoreCount(CDBCPUInfoHandle CpuInfo);

uint32_t CDBCPUInfoGetCPUThreadCount(CDBCPUInfoHandle CpuInfo);

enum CPUVendor CDBCPUInfoGetCPUVendor(CDBCPUInfoHandle CpuInfo);

enum VMMVendor CDBCPUInfoGetVMMVendor(CDBCPUInfoHandle CpuInfo);

uint64_t CDBCPUInfoGetTSCFrequency(CDBCPUInfoHandle CpuInfo);

uint64_t CDBCPUInfoGetFSBFrequency(CDBCPUInfoHandle CpuInfo);
