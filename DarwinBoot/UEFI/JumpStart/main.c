// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CoreDarwinBoot.h>
#include <Platform/EFI/EFI.h>

#define DBOD_PATH WSTRING("\\System\\Library\\CoreServices\\boot.efi")
#define DBOL_PATH WSTRING("\\EFI\\DarwinBoot\\DarwinBoot.efi")

extern EFI_STATUS LoadNextLoader(EFI_DEVICE_PATH_PROTOCOL *DevicePath);

/* TODO: this. */
EFI_STATUS EFIMain(EFI_HANDLE Handle, EFI_SYSTEM_TABLE *SystemTable)
{
    return EFI_ABORTED;
}
