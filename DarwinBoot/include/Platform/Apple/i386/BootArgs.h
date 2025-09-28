// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_APPLE_I386_BOOTARGS_H__
#define __PLATFORM_APPLE_I386_BOOTARGS_H__

#include <CoreDarwinBoot/CDBBasicTypes.h>

#define XNU_COMMANDLINE_SIZE 1024

/* doesn't seem to apply for ARM64/ARM32, interesting. */
enum XNUDisplayCode {
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
    UInt8 EFIMode;   /* 32 for IA32 EFI, 64 for X64 EFI */
    UInt8 DebugMode; /* what does this actually do? */
    char CommandLine[XNU_COMMANDLINE_SIZE];
    UInt32 MemoryMapPtr;  /* 32-bit pointer/address to/of the memory map. (Physical) */
    UInt32 MemoryMapSize; /* Here's another XNU mishap: The MemMap gets copied over to a single page, which can very quickly be violated by large memory maps, Thx to OpenCorePkg & contributors for this knowledge */
    UInt32 MemoryMapDescSize;
    UInt32 MemoryMapDescVersion;
    XNUVideoArgsV1 VideoArgsV1;
    UInt32 DeviceTreePtr; /* 32-bit pointer/address to/of the DT. (Physical) */
    UInt32 DeviceTreeSize;
    UInt32 KernelAddress;                   /* Allegedly the start of __TEXT? */
    UInt32 KernelSize;                      /* Allegedly __TEXT size + __DATA size + EFI? how does this even work? Should I consult old Clover/Chameleon? */
    UInt32 EFIRuntimeSvcsPhysicalPageStart; /* "physical address of defragmented runtime pages" */
    UInt32 EFIRuntimeSvcsPhysicalPageCount;
    UInt32 EFIRuntimeSvcsVirtualPageStart; /* "virtual address of defragmented runtime pages" */
    UInt32 EFISystemTablePtr;              /* "physical address of system table in runtime area" */
    UInt32 KernelSlide;                    /* i love kernel address sliding- but, how the heck am i meant to even perform KASLR */
    UInt32 PerformanceDataAddress;
    UInt32 PerformanceDataSize;
    UInt32 KeyStoreDataAddress; /* Allegedly the APFS Volume Key sturcture? I don't actually know where to get this from unless I take to apfs.efi */
    UInt32 KeyStoreDataSize;
    UInt64 BootMemoryAddress; /* what does this even mean? EFI Loader Data addr??? */
    UInt64 BootMemorySize;
    UInt64 PhysicalMemorySize;        /* UPDATE: it is infact, the SMBIOS mem size. */
    UInt64 FSBFrequency;              /* PM timer? I'd need to read OC for this. */
    UInt64 PCIConfigSpaceBaseAddress; /* grab from MCFG table */
    UInt32 PCIConfigSpaceStartBusNumber;
    UInt32 PCIConfigSpaceEndBusNumber;
    UInt32 CSRActiveConfig;        /* System Integrity Protection - active config */
    UInt32 CSRCapabilities;        /* caps? where do i find the values for these */
    UInt32 BootSMCPLimit;          /* This is read via AppleSmc in the MacEFI ROM/Mac UEFIs, so it's not applicable to us */
    UInt16 BootProgressMeterStart; /* what */
    UInt16 BootProgressMeterEnd;   /* what */
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

#endif /* __PLATFORM_APPLE_I386_BOOTARGS_H__ */
