// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

enum {
    kFlattenedDTNodeBegin = 1,
    kFlattenedDTNodeEnd,
    kFlattenedDTNodeProperty,
    kFlattenedDTNodeNoOp,
    kFlattenedDTEnd,
} typedef FlattenedDTToken;
