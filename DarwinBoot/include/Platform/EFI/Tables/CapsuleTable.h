// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/EFI/Types.h>

struct {
    UInt32 CapsuleArrayNumber;
    EFI_CAPSULE_HEADER *CapsulePtr[] __counted_by(CapsuleArrayNumber);
} typedef EFI_CAPSULE_TABLE;

