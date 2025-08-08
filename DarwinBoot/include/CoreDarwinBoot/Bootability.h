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
    kBootabilityFileTypeIMG4,   // Merge with kBootabilityFileTypeMach?
    kBootabilityFileTypePECOFF, // PE/COFF - A UEFI image.
} typedef BootabilityFileType;

enum {
    kBootabilityFileSubTypeUnspecified = 0,
    kBootabilityFileSubTypeMultiArch, // Mach FAT file.
} typedef BootabilityFileSubType;

/*!
 * @group      Bootability File
 *
 * @abstract   Representation of a bootable file.
 */
typedef struct _BootabilityFile *BootabilityFileRef;

BootabilityFileType BootabilityFileGetType(BootabilityFileRef File);
BootabilityFileSubType BootabilityFileGetSubType(BootabilityFileRef File);

/*!
 * @group      Bootability Volume
 *
 * @abstract   Representation of a bootable volume.
 *
 * @discussion This exists in the event that one volume has multiple bootable files, such as a linux kernel, or other files.
 */
typedef struct _BootabilityVolume *BootabilityVolumeRef;

typedef void (*BootabilityVolumeIteratorCallback)(BootabilityVolumeRef Volume, void *Context);

/*!
 * @function BootabilityVolumeGetName
 *
 * @param Volume  The volume.
 *
 * @result Returns the name of the bootable volume.
 */
const char *BootabilityVolumeGetName(BootabilityVolumeRef Volume);

#if USERSPACE
/*!
 * @function BootabilityVolumeGetPath
 *
 * @param Volume  The volume.
 *
 * @result Returns the path to the bootable volume.
 */
const char *BootabilityVolumeGetPath(BootabilityVolumeRef Volume);
#endif

/*!
 * @function BootabilityVolumeIterateFiles
 *
 * @param Volume   The volume.
 * @param Callback The callback to call for each available volume.
 */
void BootabilityVolumeIterateFiles(BootabilityVolumeRef Volume, BootabilityVolumeIteratorCallback Callback);

/*!
 * @group      Bootability Context
 *
 * @abstract   Interface to access bootable drives.
 *
 * @discussion Instances of Bootability need to use the Context to create Volume and File references.
 */
typedef struct _BootabilityContext *BootabilityContextRef;

// #define kBootabilityFilterArchs (1 << 0) /* Filter by architecture. */
#define kBootabilityMachOnly    (1 << 1) /* Only register Mach images. */
#define kBootabilityImg4Only    (1 << 2) /* Only register IMG4 images. */
#define kBootabilityElfOnly     (1 << 3) /* Only register ELF images. */
#define kBootabilityPeCoffOnly  (1 << 4) /* Only register PE/COFF images */

BootabilityContextRef BootabilityContextCreate(void);
BootabilityContextRef BootabilityContextCreateWithOptions(UInt32 Options);

