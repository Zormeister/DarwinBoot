// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include "CoreDarwinBoot/CDBBasicTypes.h"
#include <CoreDarwinBoot/CoreDarwinBoot.h>
#include <External/printf/printf.h>
#include <Platform/EFI/EFI.h>
#include <Platform/EFI/Protocols/LoadedImage.h>

void _putchar(char character)
{
    wchar_t wide[3];
    if (character == '\n' || character == '\r') {
        wide[0] = WSTRING('\r');
        wide[1] = WSTRING('\n');
        wide[2] = 0;
    } else {
        wide[0] = character;
        wide[1] = 0;
        wide[2] = 0;
    }

    // ST->ConOut->OutputString(ST->ConOut, wide);
}