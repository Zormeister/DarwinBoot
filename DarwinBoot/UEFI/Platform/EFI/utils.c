// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CoreDarwinBoot.h>
#include <Platform/EFI/EFI.h>
#include <Platform/EFI/Protocols/LoadedImage.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

bool EFIGuidMatches(EFI_GUID *a, EFI_GUID *b)
{
    /* would it be more efficient if i just compared each field */
    return (memcmp(a, b, sizeof(EFI_GUID)) == 0);
}
