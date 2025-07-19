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

void *EFIGetConfigurationTable(EFI_GUID *Guid)
{
    for (size_t i = 0; i < ST->NumberOfConfigurationTables; i++) {
        if (EFIGuidMatches(&ST->ConfigurationTables[i].VendorGuid, Guid)) {
            return ST->ConfigurationTables[i].VendorTable;
        }
    }

    return NULL;
}

void EFIWideStringToASCII(const wchar_t *WideString, char **AsciiOut, UInt32 Flags)
{
    size_t widelen = wcslen(WideString);
    bool invertSlashes = Flags & kEFIEncodeInvertSlashes;

    /* If the internal locale isn't already in en_US then we're cooked. */

    char *buffer = malloc(widelen + 1);
    for (size_t i = 0; i <= widelen; i++) {
        if (WideString[i] <= 255) {
            if (invertSlashes && (WideString[i] == WSTRING('\\'))) {
                buffer[i] = '/';
            } else {
                buffer[i] = WideString[i];
            }
        } else {
            /* Yeah. Uh. Fun. */
            continue;
        }
    }

    *AsciiOut = buffer;
}

void EFIASCIIToWideString(const char *String, wchar_t **WcharOut, UInt32 Flags)
{
    size_t pathlen = strlen(String);
    bool invertSlashes = Flags & kEFIEncodeInvertSlashes;

    wchar_t *buf = malloc((pathlen * sizeof(wchar_t)) + sizeof(wchar_t));

    for (size_t i = 0; i <= pathlen; i++) {
        if (invertSlashes && String[i] == '/') {
            buf[i] = WSTRING('\\');
        } else {
            buf[i] = String[i];
        }
    }
}
