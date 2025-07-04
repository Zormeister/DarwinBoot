// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <Platform/EFI/Types.h>

#define EFI_MP_SERVICES_PROTOCOL_GUID \
  {0x3fdda605,0xa76e,0x4f46, \
    {0xad,0x29,0x12,0xf4,0x53,0x1b,0x3d,0x08}}

typedef struct _EFI_MP_SERVICES_PROTOCOL EFI_MP_SERVICES_PROTOCOL;

typedef struct {
    UInt32 Package;
    UInt32 Core;
    UInt32 Thread;
} EFI_CPU_PHYSICAL_LOCATION;

typedef struct {
    UInt32 Package;
    UInt32 Module;
    UInt32 Tile;
    UInt32 Die;
    UInt32 Core;
    UInt32 Thread;
} EFI_CPU_PHYSICAL_LOCATION2;

typedef union {
    EFI_CPU_PHYSICAL_LOCATION2 Location2;
} EXTENDED_PROCESSOR_INFORMATION;

#define PROCESSOR_AS_BSP_BIT 0x1
#define PROCESSOR_ENABLED_BIT 0x2
#define PROCESSOR_HEALTH_STATUS_BIT 0x4

typedef struct {
    UInt64 ProcessorID;
    UInt32 StatusFlag;
    EFI_CPU_PHYSICAL_LOCATION Location;
    EXTENDED_PROCESSOR_INFORMATION ExtendedInfo;
} EFI_PROCESSOR_INFORMATION;

#define END_OF_CPU_LIST 0xffffffff

typedef void (*EFI_AP_PROCEDURE) (void *Argument);

struct _EFI_MP_SERVICES_PROTOCOL {
    EFI_STATUS (*GetNumberOfProcessors)(EFI_MP_SERVICES_PROTOCOL *This, UIntN *NProc, UIntN *NProcEnabled);
    EFI_STATUS (*GetProcessorInfo)(EFI_MP_SERVICES_PROTOCOL *This, UIntN *Processor, EFI_PROCESSOR_INFORMATION *InfoBuffer);
};
