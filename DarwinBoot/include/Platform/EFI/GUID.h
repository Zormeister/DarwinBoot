// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/EFI/Types.h>

/* RTVars: accessed & written by DarwinBoot for information s*/
#define COREDARWINBOOT_RUNTIME_VARIABLE_GUID \
  {0x1831ABAA,0x7FBF,0x4438,\
    {0xBF,0x3E,0x0E,0x70,0xD5,0xE0,0x24,0x47}}

#define SAL_SYSTEM_TABLE_GUID \
  {0xeb9d2d32,0x2d88,0x11d3,\
   {0x9a,0x16,0x00,0x90,0x27,0x3f,0xc1,0x4d}}

#define MPS_TABLE_GUID \
  {0xeb9d2d2f,0x2d88,0x11d3,\
   {0x9a,0x16,0x00,0x90,0x27,0x3f,0xc1,0x4d}}

extern EFI_GUID gAppleBootVariableGuid;

extern EFI_GUID gAcpiEfiConfigurationTableGuid;

extern EFI_GUID gAcpiV2EfiConfigurationTableGuid;

extern EFI_GUID gSmbiosTableGuid;

extern EFI_GUID gEfiSmbiosV3TableGuid;

extern EFI_GUID gEfiLoadedImageProtocolGuid;
