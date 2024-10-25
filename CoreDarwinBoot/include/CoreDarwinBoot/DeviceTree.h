// Copyright © 2024 Zormeister. All rights reserved.

/*
 * This file is part of DarwinBoot.
 
 * DarwinBoot is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 
 * DarwinBoot is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License along with DarwinBoot. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once
#include "CDBBasicTypes.h"

typedef struct _CDBDeviceTree *CDBDeviceTree;
typedef struct _CDBDTNode *CDBDTNode;
typedef struct _CDBDTProperty *CDBDTProperty;

struct FlatDTProperty {
    char name[32];
    UInt32 length;
    /* value sits here. */
};

struct FlatDTNode {
    UInt32 NumProperties;
    UInt32 NumChildren;
    /* properties go here */
    /* children go here */
};

/* UEFI hosts can provide Flattened DeviceTree blobs via a configuration table, these DTs are also able to be written to by a running UEFI Application */
/* TODO: Grab said blobs and translate them for XNU. */

/* Create DT handler. */
CDBDeviceTree CDBCreateDeviceTree(void);

CDBDTNode CDBDTGetRootNode(CDBDeviceTree dt);

CDBDTNode CDBDTGetNode(const char *nodePath, bool createNodeIfNotFound);
CDBDTProperty CDBDTGetProperty(CDBDTNode node, const char *propertyName);
bool CDBDTSetNodeProperty(CDBDTNode node, const char *propertyName, const UInt8 *data, UInt32 size);

bool CDBDTPropertyGetValue(CDBDTProperty prop, UInt8 **valueOut, UInt32 *sizeOut);
