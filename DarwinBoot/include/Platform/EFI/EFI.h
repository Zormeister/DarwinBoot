// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

#include <Platform/EFI/BootManager.h>
#include <Platform/EFI/EFITypes.h>
#include <Platform/EFI/GUID.h>
#include <Platform/EFI/Protocols/DevicePath.h>
#include <Platform/EFI/Protocols/GOP.h>
#include <Platform/EFI/Protocols/LoadedImage.h>
#include <Platform/EFI/Protocols/SimpleText.h>
#include <Platform/EFI/Tables.h>

extern EFI_SYSTEM_TABLE *ST;
extern EFI_BOOT_SERVICES *BS;
extern EFI_RUNTIME_SERVICES *RT;
extern EFI_LOADED_IMAGE_PROTOCOL *LIP;