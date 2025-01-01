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

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

enum {
    UART = 1,
} typedef DriverSubClass;

enum {
    Abstract = 0,
    Serial = 1,
} typedef DriverClass;

struct {
    const char *DriverName;
    void *Device;
    DriverClass Class;
    DriverSubClass SubClass;
} typedef PlatformDriver;

struct {
    const char *Compatible;

    bool (*conformsTo)(const char *Compatible);
} typedef PlatformDevice;

struct CorePlatformDriverInfo {
    const char *DrvName;
    bool *(*IsSupported)(PlatformDevice *dev);
    PlatformDriver * (*CreateDriver)(PlatformDevice *dev);
    void (*DestroyDriver)(PlatformDriver *This);
};