// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

/*
 * At it's heart, CoreDarwinBoot is designed to be as versatile as possible.
 * 
 * This becomes a challenge when handling boot files.
 *
 * Design goals:
 *  - Provide an abstract interface for FS integration
 *  - Enable the rest of CoreDarwinBoot to use these as needed to load files.
 *
 * CoreDarwinBoot's File System layer needs to be implemented at the platform level, much like
 * the CPU Info layer.
 */

typedef struct _CDBFileSystem *CDBFileSystemRef;
typedef struct _CDBFileRef *CDBFileRef;

/*
 * This function has different outputs depending on which stage of the loading process DarwinBoot is in.
 *
 * The 'Boot Volume' means the volume the payload was loaded from.
 *
 * This works well until we reach ARM loaders; where the payload isn't always going to be on the system volume.
 *
 * For Instance, the higher layer functions for loading the kernel can call this function to locate the kernel.
 * The same will work for a system version reading and grabbing kexts from the root volume.
 */
CDBFileSystemRef CDBFileSystemGetBootVolume(void);

bool CDBFileSystemIsBootable(CDBFileSystemRef FileSystem);

/* TODO: Alternative names. */
CDBFileRef CDBFileSystemCreateFileRef(CDBFileSystemRef FileSystem, const char *Path);

#pragma mark CoreDarwinBoot File functions

