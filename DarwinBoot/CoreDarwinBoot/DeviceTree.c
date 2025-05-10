// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/DeviceTree.h>

struct _CDBDeviceTree {
    CDBDTNode RootNode;
};

struct _CDBDTNode {
    CDBDTNode FirstChild;
    CDBDTNode LastChild;
    CDBDTProperty FirstProperty;
    CDBDTProperty LastProperty;
};

struct _CDBDTProperty {
    const char *Name;
    enum DTDataType DataType;
    size_t DataSize;
    void *Data;
    CDBDTProperty NextProperty;
};

bool CDBInitDeviceTree(void) {


    return true;
}
