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
    kBootabilityFileTypeUnspecified = 0,
    kBootabilityFileTypeMach,   // any Mach-O file.
    kBootabilityFileTypeELF,    // any ELF32 or ELF64 file.
    kBootabilityFileTypeIMG4,   // Merge with BOOTABILITY_FILE_TYPE_MACH?
    kBootabilityFileTypePECOFF, // PE/COFF - A UEFI image.
} typedef BootabilityFileType;

enum {
    kBootabilityFileSubTypeUnspecified = 0,
    kBootabilityFileSubTypeMultiArch, // Mach FAT file.
} typedef BootabilityFileSubType;

/*
 * how the SHIT does any of the macOS stack get ahold of the correct kernel?
 */

struct {
    BootabilityFileType Type;
    BootabilityFileSubType SubType;
    const char *FilePath;
    const char *FileName;
} typedef BootabilityFile;

struct {
    BootabilityFile *File;
    const char *Name;
} typedef BootabilityVolume;

bool BootabilityInit();
