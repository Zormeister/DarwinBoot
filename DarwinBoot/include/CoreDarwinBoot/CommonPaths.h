// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

#define DARWINBOOT_CONFIG_PATH "/Library/Preferences/SystemConfiguration/com.zormeister.DarwinBoot.plist"

#if AUTORAMDISK_PB

// ProjectBuilder integration?
// I need to work out how to sign/chunklist DMGs ffs
#define AUTORAMDISK_PATH "/Library/Caches/com.zormeister.ProjectBuilder/DarwinRAMDisk.dmg"
#define AUTORAMDISK_DEV_PATH "/Library/Caches/com.zormeister.ProjectBuilder/DarwinRAMDisk.development.dmg"
#else
#define AUTORAMDISK_PATH "/com.apple.recovery.boot/BaseSystem.dmg"
#define AUTORAMDISK_DEV_PATH "/com.apple.recovery.boot/InternalSystem.dmg" // i have no idea if this is actually the case
#endif
