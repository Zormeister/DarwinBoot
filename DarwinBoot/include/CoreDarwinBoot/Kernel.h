// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/DeviceTree.h>
#include <CoreDarwinBoot/BootArgs.h>

/*
 * @group     Kernel Ref
 *
 * @abstract  This represents the kernel,
 */
typedef struct _CDBKernel *CDBKernelRef;

CDBKernelRef CDBKernelCreateFromBinary(const UInt8 *Binary, size_t BinarySize);

/* IsCached == true when the kernel is wrapped in a prelinkedkernel or kernel collection. */
bool CDBKernelIsCached(CDBKernelRef);

/* IsPrelinked -> is the kernel packaged in a prelinkedkernel format, or does it use the prelinkedkernel format */
bool CDBKernelIsPrelinked(CDBKernelRef);

/* IsFileset -> is the kernel packaged into a KernelCollection || does the kernel use the Fileset format */
bool CDBKernelIsFileset(CDBKernelRef);

/* This creates entries for the DeviceTree, whch the kernel will load in KLDBootstrap.  */
bool CDBKernelLoadExtensionsFromVolume(CDBKernelRef Kernel, CDBDeviceTreeRef DeviceTree, const char *pathFromRoot);

UInt32 CDBKernelGetMajorVersion(CDBKernelRef Kernel);
/* ^ TODO: Extend <Platform/Apple/MachO.h> to allow symbol lookup + linking for pre-boot binaries. */

/*
 * @typedef   Kernel Preflight Callback
 */
typedef void (*KernelPreflightCallback)(void *Context);

typedef void __attribute__((sysv_abi)) (*XNUKernelMainFunc)(XNUBootArguments *kernel_args);
/* ^ I believe this is the function signature? Someone please correct me before I'm wrong. */
