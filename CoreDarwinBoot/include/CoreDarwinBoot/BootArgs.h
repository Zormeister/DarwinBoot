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
#include "CDBBasicTypes.h"

#if TARGET_X64 || TARGET_IA32

#define XNU_COMMANDLINE_SIZE 1024

/* doesn't seem to apply for ARM64/ARM32, interesting. */
enum XNUDisplayCode : UInt32 {
    GraphicsMode = 1,
    FramebufferTextMode = 2,
};

struct {
    UInt32 BaseAddress;
    UInt32 DiplayCode;
    UInt32 RowBytes;
    UInt32 Width;
    UInt32 Height;
    UInt32 PixelDepth;
} typedef XNUVideoArgsV1;

struct {
    UInt32 DisplayCode;
    UInt32 RowBytes;
    UInt32 Width;
    UInt32 Height;
    UInt32 PixelDepth;
    UInt32 Rotation;
    UInt8 RsvdBytes[3];
    UInt32 Rsvd[6];
    UInt64 BaseAddress;
} typedef XNUVideoArgs;

#define XNU_BOOT_ARGS_CURRENT_VERSION  2
#define XNU_BOOT_ARGS_CURRENT_REVISION 1

/* TODO: Legacy Backwards-compat? Mac OS X Snow Leopard and older have a different structure */

struct {
    UInt16 Revision;
    UInt16 Version;
    UInt8 EFIMode; /* 32 for IA32 EFI, 64 for X64 EFI */
    UInt8 DebugMode; /* what does this actually do? */
    char CommandLine[XNU_COMMANDLINE_SIZE];
    UInt32 MemoryMapPtr; /* 32-bit pointer/address to/of the memory map. (Physical) */
    UInt32 MemoryMapSize; /* Here's another XNU mishap: The MemMap gets copied over to a single page, which can very quickly be violated by large memory maps, Thx to OpenCorePkg & contributors for this knowledge */
    UInt32 MemoryMapDescSize;
    UInt32 MemoryMapDescVersion;
    XNUVideoArgsV1 VideoArgsV1;
    UInt32 DeviceTreePtr; /* 32-bit pointer/address to/of the DT. (Physical) */
    UInt32 DeviceTreeSize;
    UInt32 KernelAddress; /* Allegedly the start of __TEXT? */
    UInt32 KernelSize; /* Allegedly __TEXT size + __DATA size + EFI? how does this even work? Should I consult old Clover/Chameleon? ?*/
    UInt32 EFIRuntimeSvcsPhysicalPageStart; /* "physical address of defragmented runtime pages" */
    UInt32 EFIRuntimeSvcsPhysicalPageCount;
    UInt32 EFIRuntimeSvcsVirtualPageStart; /* "virtual address of defragmented runtime pages" */
    UInt32 EFISystemTablePtr; /* "physical address of system table in runtime area" */
    UInt32 KernelSlide; /* i love kernel address sliding- but, how the heck am i meant to even perform KASLR */
    UInt32 PerformanceDataAddress;
    UInt32 PerformanceDataSize;
    UInt32 KeyStoreDataAddress; /* Allegedly the APFS Volume Key sturcture? I don't actually know where to get this from unless I take to apfs.efi */
    UInt32 KeyStoreDataSize;
    UInt64 BootMemoryAddress; /* what does this even mean? EFI Loader Data addr??? */
    UInt64 BootMemorySize;
    UInt64 PhysicalMemorySize; /* UPDATE: it is infact, the SMBIOS mem size. */
    UInt64 FSBFrequency; /* PM timer? I'd need to read OC for this. */
    UInt64 PCIConfigSpaceBaseAddress; /* grab from MCFG table */
    UInt32 PCIConfigSpaceStartBusNumber;
    UInt32 PCIConfigSpaceEndBusNumber;
    UInt32 CSRActiveConfig; /* System Integrity Protection - active config */
    UInt32 CSRCapabilities; /* caps? where do i find the values for these */
    UInt32 BootSMCPLimit; /* This is read via AppleSmc in the MacEFI ROM/Mac UEFIs, so it's not applicable to us */
    UInt16 BootProgressMeterStart; /* what */
    UInt16 BootProgressMeterEnd; /* what */
    XNUVideoArgs VideoArgs;
    UInt64 KCHeadersVirtualAddress; /* VAddr of the filesets? or just of the whole file? */
    /* ARV, which i believe stands for Authenticated Root Volume, is the new snapshot sealing feature from macOS Big Sur */
    UInt64 ARVRootHashAddress; /* IM4P? */
    UInt64 ARVRootHashSize;
    UInt64 ARVRootManifestAddress; /* i assume this is an IM4M */
    UInt64 ARVRootManifestSize;
    UInt64 BaseSystemARVRootHashAddress;
    UInt64 BaseSystemARVRootHashSize;
    UInt64 BaseSystemARVRootManifestAddress; /* i assume this is an IM4M */
    UInt64 BaseSystemARVRootManifestSize;
    UInt32 Reserved[692];
} typedef XNUBootArguments;

/* do i need to BootServices->SetVirtualAddressMap() before booting XNU? */
/* does it expect me to have switched to Virtual Memory before kernel load? */

#endif

#if TARGET_ARM32 || TARGET_ARM64

/* unsigned long */

/* man wtf why */
#define XNU_COMMANDLINE_SIZE 256

#define DISPLAYPARAMS_DEPTH_SHIFT (0)
#define DISPLAYPARAMS_ROTATION_SHIFT (8)
#define DISPLAYPARAMS_SCALE_SHIFT (16)
#define DISPLAYPARAMS_BOOTROTATE_SHIFT (24)

struct {
    unsigned long BaseAddress;
    unsigned long DiplayCode;
    unsigned long RowBytes;
    unsigned long Width;
    unsigned long Height;
    unsigned long DisplayParams; /* pixel depth + rotation + scale + boot rotation? */
} typedef XNUVideoArgs;

#define BOOT_FLAG_DARKBOOT (1 << 0)

struct {
    UInt16 Revision;
    UInt16 Version;
    UInt32 VirtualBase;
    UInt32 PhysicalBase;
    UInt32 MemorySize;
    UInt32 TopOfKernelData; /* what, "Highest physical address used in kernel data area", refer to BCM2835/BCM2836/BCM2837 mem map? */
    XNUVideoArgs VideoArgs;
    UInt32 MachineType; /* ??? */
    void *DeviceTreePtr; /* i assume this helps with native addressing, in the event that the DT is outside of a 32-bit address */
    UInt32 DeviceTreeSize;
    char CommandLine[XNU_COMMANDLINE_SIZE];
    UInt32 BootFlags;
    UInt32 RealMemorySize; /* wtf does this even mean, MemorySize == memory size given to the kernel's operating space??? */
} typedef XNUBootArguments;

#endif

/* apparently you can also load Dexts this way, interesting. */
struct {
    UInt32 InfoPlistAddr;
    UInt32 InfoPlistSize;
    UInt32 ExecAddress;
    UInt32 ExecSize;
    UInt32 BundlePathAddr;
    UInt32 BundlePathLength;
} typedef BootKernelExtensionEntry;

/*!
  @function CDBInitKernelBootArguments
  @abstract Allocates a local XNUBootArgs instance, which can be accessed by CoreDarwinBoot and other services within the same UEFI Application
  @result Returns true if the operation was successful
 */
extern bool CDBInitKernelBootArguments(void);

/*!
  @function CDBAddKernelExtensionToBoot
  @abstract Allocates a BootKernelExtensionEntry instance & adds it to the DeviceTree
  @result Returns true if the operation was successful
 */
extern bool CDBAddKernelExtensionToBoot(const UInt8 *infoPlist, const UInt32 plistSize, const UInt8 *exec, const UInt32 execSize, const char *pathToBundle);