// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CoreDarwinBoot.h>

/*
 * CoreHFS
 *
 * CoreHFS is supposed to be a file-system driver that's abstract enough to work on the ARM loader and UEFI loader
 * with minimal effort in bridging the two.
 */

/* Abstract interafce to read the disk. */
typedef struct {
    void *Context;

    errno_t (*ReadBlock)(void *Context, UInt64 Block, void *Buffer, size_t BufferSize);
    errno_t (*WriteBlock)(void *Context, UInt64 Block, const void *Buffer, size_t BufferSize);
    errno_t (*ReadDisk)(void *Context, UInt64 Offset, void *Buffer, size_t BufferSize);
    errno_t (*WriteDisk)(void *Context, UInt64 Offset, const void *Buffer, size_t BufferSize);
} CoreHFSDiskCallbacks;

#define kCoreHFSInitVersion 0x010000

typedef struct {
    UInt32 Version;

    CoreHFSDiskCallbacks Disk;

    UInt32 BlockSize;
} CoreHFSInitData;

typedef struct _CoreHFSDriver *CoreHFSDriver;

CoreHFSDriver CoreHFSCreateDriver(CoreHFSInitData *InitData);
void CoreHFSFinalise(CoreHFSDriver Drv);

/*!
 * @function CoreHFSReadFile
 *
 * @param Drv        The CoreHFS context/driver reference.
 * @param FilePath   The path to the file to read.
 * @param Buffer     Pointer to the buffer to read the file into.
 * @param BufferSize Pointer to the buffer size.
 *
 * @result           A POSIX error number.
 */
errno_t CoreHFSReadFile(CoreHFSDriver Drv, const char *FilePath, void *Buffer, size_t *BufferSize);

errno_t CoreHFSGetFileMetadata(CoreHFSDriver Drv, const char *FilePath);
