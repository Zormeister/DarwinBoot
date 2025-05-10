// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CoreDarwinBoot.h>
#include <Platform/EFI/EFI.h>
#include <Platform/EFI/Protocols/LoadedImage.h>

void *platform_malloc(size_t size) {
    if (BS == NULL) { return NULL; }

    void *outbuffer;
    EFI_STATUS status = BS->AllocatePool(EfiLoaderData, size, &outbuffer);
    if (status != EFI_SUCCESS || outbuffer == NULL) {
        ST->ConOut->OutputString(ST->ConOut, WSTRING("[CDB][UEFI]: Memory Allocation failed.\n"));
        return NULL;
    }
    return outbuffer;
}
