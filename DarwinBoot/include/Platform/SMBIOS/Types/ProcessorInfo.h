// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_SMBIOS_TYPES_PROCESSORINFO_H__
#define __PLATFORM_SMBIOS_TYPES_PROCESSORINFO_H__

#include <Platform/SMBIOS/Types/EntryPoint.h>
#include <Platform/SMBIOS/Types/TableHeader.h>

typedef enum {
    kSMBIOSProcessorTypeOther = 0x1,
    kSMBIOSProcessorTypeUnknown = 0x2,
    kSMBIOSProcessorTypeCentralProcessor = 0x3,
    kSMBIOSProcessorTypeMathProcessor = 0x4,
    kSMBIOSProcessorTypeDSPProcessor = 0x5,
    kSMBIOSProcessorTypeVideoProcessor = 0x6,
} SMBIOSProcessorType;

// this enum was referenced from SMBIOS v3.8.0
// please update when necessary
typedef enum {
    kSMBIOSProcessorFamilyOther = 0x1,
    kSMBIOSProcessorFamilyUnknwon = 0x2,

    // legacy intel i presume.
    kSMBIOSProcessorFamily8086,
    kSMBIOSProcessorFamily80286,
    kSMBIOSProcessorFamilyI386,
    kSMBIOSProcessorFamilyI486,
    kSMBIOSProcessorFamily8087,
    kSMBIOSProcessorFamily80287,
    kSMBIOSProcessorFamily80387,
    kSMBIOSProcessorFamily80487,
    kSMBIOSProcessorFamilyPentium,
    kSMBIOSProcessorFamilyPentiumPro,
    kSMBIOSProcessorFamilyPentiumII,
    kSMBIOSProcessorFamilyPentiumWithMMX,
    kSMBIOSProcessorFamilyCeleron,
    kSMBIOSProcessorFamilyPentiumIIXeon,
    kSMBIOSProcessorFamilyPentiumIII,
    kSMBIOSProcessorFamilyM1,
    kSMBIOSProcessorFamilyM2,
    kSMBIOSProcessorFamilyCeleronM,
    kSMBIOSProcessorFamilyPentium4HT,
    
    kSMBIOSProcessorFamilyAMDDuron = 0x18,
    kSMBIOSProcessorFamilyAMDK5Family,
    kSMBIOSProcessorFamilyAMDK6Family,
    kSMBIOSProcessorFamilyAMDK6Family2,
    kSMBIOSProcessorFamilyAMDK6Family3,
    kSMBIOSProcessorFamilyAMDAthlonFamily,
} SMBIOSProcessorFamily;

typedef struct {
    SMBIOSTableHeader Header;
    SMBIOSString SocketDesignation; // 'FP6'

} SMBIOSProcessorInfo;

#endif /* __PLATFORM_SMBIOS_TYPES_PROCESSORINFO_H__ */
