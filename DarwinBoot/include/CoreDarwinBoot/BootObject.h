// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/Array.h>
#include <CoreDarwinBoot/FileSystem.h>
#include <CoreDarwinBoot/CDBBasicTypes.h>

CDB_API_BEGIN

/*!
 * @group BootObject
 *
 * @abstract
 * Abstract representation of a boot object, be it:
 * - a firmware file found in `/usr/standalone/firmware`
 * - a PE/COFF file found in `EFI/BOOT/`
 * - an instance of `boot.efi`
 * - a UEFI driver
 */

CDB_OBJECT_DEFINE(BootObject);

/*!
 * @function CDBBootObjectGetAllFromFileSystem
 * Collect all available boot objects from a file system,
 *
 * @param  
 */
CDBArrayRef CDBBootObjectGetAllFromFileSystem(CDBFileSystemRef fileSystem);

CDB_API_END
