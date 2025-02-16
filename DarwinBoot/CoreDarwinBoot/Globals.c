// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CoreDarwinBoot.h>

#if CONFIG_DEBUG == 1 || CONFIG_DEVELOPMENT == 1
uint8_t gDebug = 1;
uint8_t gProduction = 0;
uint8_t gLogPolicy = 0;
#else
uint8_t gDebug = 0;
uint8_t gProduction = 1;
uint8_t gLogPolicy = 0;
#endif

const char *gCompilerToolsVersion = COMPILER_VERSION;
const char *gCompilerToolsToolchain = BUILD_TOOL;