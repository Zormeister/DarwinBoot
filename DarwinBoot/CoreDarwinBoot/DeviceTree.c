// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include "CoreDarwinBoot/CDBBasicTypes.h"
#include <CoreDarwinBoot/DeviceTree.h>
#include <stdlib.h>
#include <string.h>

struct _CDBDeviceTree {
    CDBDTNodeRef RootNode;
};

struct _CDBDTNode {
    CDBDTNodeRef FirstChild;
    CDBDTNodeRef LastChild;
    CDBDTPropertyRef FirstProperty;
    CDBDTPropertyRef LastProperty;
};

struct _CDBDTProperty {
    const char *Name;
    enum DTDataType DataType;
    size_t DataSize;
    void *Data;
    CDBDTPropertyRef NextProperty;
};

#if __x86_64__ || __i386__
#define kRootNodeName    "/"
#define kRootNodeNameLen 2
#elif __arm64__ || __arm64__
#define kRootNodeName    "device-tree"
#define kRootNodeNameLen 12
#endif

CDBDeviceTreeRef CDBDeviceTreeCreate(void)
{
    CDBDeviceTreeRef newDeviceTree = (CDBDeviceTreeRef)malloc(sizeof(struct _CDBDeviceTree));

    /* Allocate the root node. */
    newDeviceTree->RootNode = (CDBDTNodeRef)malloc(sizeof(struct _CDBDTNode));
    CDBDTNodeSetProperty(newDeviceTree->RootNode, "name", (const UInt8 *)kRootNodeName, kRootNodeNameLen);

    return newDeviceTree;
}

CDBDTPropertyRef CDBDTNodeGetProperty(CDBDTNodeRef node, const char *propertyName)
{
    CDBDTPropertyRef prop = node->FirstProperty;
    while (prop != NULL) {
        if (strncmp(prop->Name, propertyName, strlen(prop->Name)) == 0) {
            return prop;
        } else {
            prop = prop->NextProperty;
        }
    }
    return NULL;
}

bool CDBDTNodeSetProperty(CDBDTNodeRef node, const char *propertyName, const UInt8 *data, UInt32 size)
{
    CDBDTPropertyRef ref = CDBDTNodeGetProperty(node, propertyName);

    if (ref) {
        /* update the property */
        if (ref->DataSize >= size) {
            memcpy(ref->Data, data, size);
            return true;
        } else {
            realloc(ref, sizeof(struct _CDBDTProperty) + size);
            memcpy(ref->Data, data, size);
            return true;
        }
    } else {
        CDBDTPropertyRef newProperty = malloc(sizeof(struct _CDBDTProperty) + size);
        memcpy(ref->Data, data, size);
        ref->Name = propertyName;
        if (node->LastProperty == NULL) {
            node->FirstProperty = newProperty;
            node->LastProperty = newProperty;
        } else {
            node->LastProperty->NextProperty = newProperty;
            node->LastProperty = newProperty;
        }
        return true;
    }
    return false;
}
