// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_TABLES_CAPSULETABLE_H__
#define __PLATFORM_EFI_TABLES_CAPSULETABLE_H__

#include <Platform/EFI/Types.h>

struct {
    UInt32 CapsuleArrayNumber;
    EFI_CAPSULE_HEADER *CapsulePtr[] __counted_by(CapsuleArrayNumber);
} typedef EFI_CAPSULE_TABLE;

#endif /* __PLATFORM_EFI_TABLES_CAPSULETABLE_H__ */
