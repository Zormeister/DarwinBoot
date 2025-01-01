// Copyright © 2024 Zormeister.

/*
 * This file is part of DarwinBoot.
 
 * DarwinBoot is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 
 * DarwinBoot is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License along with DarwinBoot. If not, see <https://www.gnu.org/licenses/>.
 */

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
