// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CoreDarwinBoot.h>
#include <Platform/EFI/EFI.h>
#include <Platform/EFI/Protocols/LoadedImage.h>
#include <string.h>

bool EFIGuidMatches(EFI_GUID *a, EFI_GUID *b) {
    /* would it be more efficient if i just compared each field */
    return (memcmp(a, b, sizeof(EFI_GUID)) == 0);
}

void *EFIGetConfigurationTable(EFI_GUID *Guid) {
    for (size_t i = 0; i < ST->NumberOfConfigurationTables; i++) {
        if (EFIGuidMatches(&ST->ConfigurationTables[i].VendorGuid, Guid)) {
            return ST->ConfigurationTables[i].VendorTable;
        }
    }

    return NULL;
}
