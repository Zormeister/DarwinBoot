// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

/*
 * Bootability
 * not at all named after BootabilityBrain (a part of the UniversalMac images)
 *
 * Bootability is supposed to be able to locate bootable drives, alongside the boot file's path and extra data to help the loading process
 */

enum {
    BOOTABILITY_FILE_TYPE_UNSPECIFIED = 0,
    BOOTABILITY_FILE_TYPE_MACH,
    BOOTABILITY_FILE_TYPE_ELF,
    BOOTABILITY_FILE_TYPE_IMG4, // Merge with BOOTABILITY_FILE_TYPE_MACH?
    BOOTABILITY_FILE_TYPE_PECOFF, // PE/COFF - A UEFI image.
} typedef BootabilityFileType;

enum {
    BOOTABILITY_FILE_SUBTYPE_UNSPECIFIED = 0,
    BOOTABILITY_FILE_SUBTYPE_FAT, // Mach FAT file.
} typedef BootabilityFileSubType;

struct {
    BootabilityFileType FileType;
    BootabilityFileSubType FileSubType;
    const char *FilePath;
    const char *FileName;
} typedef BootabilityFile;

struct {
    BootabilityFile *File;
    const char *Name;
} typedef BootabilityVolume;

bool BootabilityInit();

