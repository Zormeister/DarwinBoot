// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_APPLE_DEVICETREE_H__
#define __PLATFORM_APPLE_DEVICETREE_H__

#include <stdint.h>

struct BinaryDTProperty {
    char name[32];
    UInt32 length;
    /* value sits here. */
};

struct BinaryDTNode {
    UInt32 NumProperties;
    UInt32 NumChildren;
    /* properties go here */
    /* children go here */
};

#endif /* __PLATFORM_APPLE_DEVICETREE_H__ */
