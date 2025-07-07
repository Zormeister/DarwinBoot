// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

/*
 * CoreHFS
 * 
 * CoreHFS is supposed to be a file-system driver that's abstract enough to work on the ARM loader and UEFI loader
 * with minimal effort in bridging the two.
 *
 */


/* Abstract interafce to read the disk. */
typedef struct {
    void *Context;

    int (*ReadBlock)(void *Context, UInt64 Block, void *Buffer, size_t BufferSize);
    int (*WriteBlock)(void *Context, UInt64 Block, const void *Buffer, size_t BufferSize);
} CoreHFSDiskCallbacks;


#define kCoreHFSInitVersion 0x010000

typedef struct {
    UInt32 Version;

    CoreHFSDiskCallbacks Disk;

    UInt32 BlockSize;
} CoreHFSInitData;

typedef struct _CoreHFSDriver *CoreHFSDriver;

CoreHFSDriver CoreHFSCreateDriver(CoreHFSInitData *InitData);
