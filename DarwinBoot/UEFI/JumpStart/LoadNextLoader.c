// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include "CoreDarwinBoot/FileSystem.h"
#include <CoreDarwinBoot/CoreDarwinBoot.h>
#include <Platform/EFI/EFI.h>

#define ONDISK_PATH WSTRING("\\System\\Library\\CoreServices\\boot.efi")
#define ONESP_PATH  WSTRING("\\EFI\\DarwinBoot\\DarwinBoot.efi")

EFI_STATUS LoadNextLoader(EFI_DEVICE_PATH_PROTOCOL *DevicePath)
{
    /* hm. */
    CDBFileSystemRef FS = CDBFileSystemGetBootVolume();

    /* Now, next objective: get the second stage loader going. */

    return EFI_ABORTED;
}
