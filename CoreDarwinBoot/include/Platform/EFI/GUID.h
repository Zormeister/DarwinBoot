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
#include "EFITypes.h"

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
