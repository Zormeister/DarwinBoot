// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef _COREHFS_COREHFS_H_
#define _COREHFS_COREHFS_H_

#include "CoreHFSTypes.h"

#if defined __cplusplus
extern "C"
{
#endif

typedef void *HFS_HANDLE;
typedef void *HFS_CALLBACK_HANDLE;

struct {
    HFS_RETURN_CODE (*allocateMemory)(HFS_CALLBACK_HANDLE hClient, 
                                      const HFS_ALLOCATE_MEMORY_INPUT *pInput,
                                      HFS_ALLOCATE_MEMORY_OUTPUT *pOutput);
    HFS_RETURN_CODE (*readDisk)(HFS_CALLBACK_HANDLE hClient,
                                const HFS_READ_DISK_INPUT *pInput);
    HFS_RETURN_CODE (*writeDisk)(HFS_CALLBACK_HANDLE hClient,
                                 const HFS_WRITE_DISK_INPUT *pInput);
    HFS_RETURN_CODE (*readBlock)(HFS_CALLBACK_HANDLE hClient,
                                 const HFS_READ_BLOCK_INPUT *pInput);
    HFS_RETURN_CODE (*writeBlock)(HFS_CALLBACK_HANDLE hClient,
                                  const HFS_WRITE_BLOCK_INPUT *pInput);
} typedef HFS_CALLBACKS;

#define HFS_API_VERSION 0x0000100

struct {
    uint32_t version;
    HFS_CALLBACK_HANDLE hClient;
    HFS_CALLBACKS *pCallbacks;
} typedef HFS_CREATE_INFO;

HFS_RETURN_CODE HfsCreate(const HFS_CREATE_INFO *pCreateInfo);

#if defined (__cplusplus)
}
#endif

#endif /* _COREHFS_COREHFS_H_ */
