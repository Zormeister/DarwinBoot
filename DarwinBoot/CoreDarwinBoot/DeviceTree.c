// Copyright (C) 2024 Zormeister, Licensed under the GPLv3 or later.

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
    UInt32 DataSize;
    void *Data;
    CDBDTProperty NextProperty;
};

bool CDBInitDeviceTree(void) {
    
    return true;
}