// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef _COREHFS_COREHFSTYPES_H_
#define _COREHFS_COREHFSTYPES_H_

#include <stdint.h>
#include <errno.h>

#if defined __cplusplus
extern "C"
{
#endif

typedef uint64_t HFS_BLOCK;
typedef void *HFS_BUFFER;

enum _HfsReturn {
    HFS_OK = 0,

    HFS_NOT_FOUND = 1,
    HFS_NO_MEMORY,
    HFS_BAD_HEADER,
    HFS_INVALID_PARAMETER,
} typedef HFS_RETURN_CODE;

typedef wchar_t HFS_WCHAR;

struct _HfsAllocateMemoryInput {
    size_t size;
} typedef HFS_ALLOCATE_MEMORY_INPUT;

struct _HfsAllocateMemoryOutput {
    void *memory;
} typedef HFS_ALLOCATE_MEMORY_OUTPUT;

struct _HfsFreeMemoryInput {
    void *memory;
    size_t memorySize;
} typedef HFS_FREE_MEMORY_INPUT; 

struct _HfsReadBlockInput {
    size_t size;
    HFS_BLOCK block;
    HFS_BUFFER buffer;
} typedef HFS_READ_BLOCK_INPUT;

struct _HfsReadDiskInput {
    size_t size;
    size_t offset;
    HFS_BUFFER buffer;
} typedef HFS_READ_DISK_INPUT;

struct _HfsWriteBlockInput {
    size_t size;
    HFS_BLOCK block;
    HFS_BUFFER buffer;
} typedef HFS_WRITE_BLOCK_INPUT;

struct _HfsWriteDiskInput {
    size_t size;
    size_t offset;
    HFS_BUFFER buffer;
} typedef HFS_WRITE_DISK_INPUT;


#if defined (__cplusplus)
}
#endif

#endif /* _COREHFS_COREHFSTYPES_H_ */
