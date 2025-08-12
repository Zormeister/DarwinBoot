// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/FileSystem.h>

//
// services for accessing darwinOS's (i say darwinOS when i mean macOS, iOS, etc style OSes, PureDarwin included) configuration
//

typedef struct _CDBDarwinSystem *CDBDarwinSystemRef;

//
// CoreDarwinBoot - Darwin System
//
// This basically is a series of functions for determining attributes of the Darwin OS contained in the filesystem
//
// Eg:
//
// const char *OSProductName = CDBDarwinSystemGetProductName(system);
//
// if (!strncmp(OSProductName, "PureDarwin", strlen(OSProductName))) {
//    ...
// }
//
// This is great for debugging too, if /System/Library/CoreServices/SystemVersion.plist has nice values.
//

CDBDarwinSystemRef CDBDarwinSystemCreateFromFS(CDBFileSystemRef FileSystem);

// reads bootcaches.plist in the root volume, otherwise it looks itself.
const char *CDBDarwinSystemGetKernelPath(CDBDarwinSystemRef System);

const char *CDBDarwinSystemGetSystemVersion(CDBDarwinSystemRef System);

const char *CDBDarwinSystemGetProductName(CDBDarwinSystemRef System);
