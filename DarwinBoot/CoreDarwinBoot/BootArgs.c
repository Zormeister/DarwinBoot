// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/BootArgs.h>
#include <CoreDarwinBoot/CoreDarwinBoot.h>

static XNUBootArguments *CurrentArguments;

bool CDBInitKernelBootArguments() {
    CurrentArguments = (XNUBootArguments *)malloc(sizeof(XNUBootArguments));
    if (CurrentArguments == NULL) {
        return false;
    }
#if DEVELOPMENT || DEBUG
    snprintf(CurrentArguments->CommandLine, sizeof(CurrentArguments->CommandLine), "-v");
#endif
    return true;
}