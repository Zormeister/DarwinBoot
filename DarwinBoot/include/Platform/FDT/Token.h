// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_FDT_TOKEN_H__
#define __PLATFORM_FDT_TOKEN_H__

#include <CoreDarwinBoot/CDBBasicTypes.h>

enum {
    kFlattenedDTNodeBegin = 1,
    kFlattenedDTNodeEnd,
    kFlattenedDTNodeProperty,
    kFlattenedDTNodeNoOp,
    kFlattenedDTEnd,
} typedef FlattenedDTToken;

#endif /* __PLATFORM_FDT_TOKEN_H__ */
