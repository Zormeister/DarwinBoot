// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CoreDarwinBoot.h>

const char *gCompilerToolsVersion = COMPILER_VERSION;
const char *gCompilerToolsToolchain = BUILD_TOOL;

bool CDBIsDevelopment(void) {
#if CONFIG_DEVELOPMENT || CONFIG_DEBUG
    return true;
#else
    return false;
#endif
}
