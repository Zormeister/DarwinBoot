// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <panic.h>
#include <CoreDarwinBoot/EFI.hpp>

using namespace CDB;

static EFI::Interface sSystemInterface;

EFI::Interface *EFI::getSystemInterface() { return &sSystemInterface; }

bool EFI::Initialize(EFI_HANDLE hHandle, EFI_SYSTEM_TABLE *pSystemTable)
{
    if (sSystemInterface.initWithSystemTableAndHandle(pSystemTable, hHandle)) {
        return true;
    } else {
        panic("[EFI]: ");
    }

    return false;
}

bool EFI::Interface::initWithSystemTableAndHandle(EFI_SYSTEM_TABLE *pSystemTable, EFI_HANDLE hHandle)
{
    fHandle = hHandle;

    if (!(pSystemTable->Header.Signature == EFI_SYSTEM_TABLE_SIGNATURE)) {
        /* malformed signature */
        return false;
    }

    Object *self = dynamic_cast<Object *>(this);

    return true;
}


