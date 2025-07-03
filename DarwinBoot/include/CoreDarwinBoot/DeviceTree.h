// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <Platform/FDT/Header.h>

typedef struct _CDBDeviceTree *CDBDeviceTreeRef;
typedef struct _CDBDTNode *CDBDTNodeRef;
typedef struct _CDBDTProperty *CDBDTPropertyRef;

enum DTDataType {
    Structure = 1,
    Integer8,
    Integer16,
    Integer32,
    Integer64,
    Data, /* This represents any binary data. All DT data should be padded to fit a 'chunk' of data */
    String,
    Any,
};

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

/* UEFI hosts can provide Flattened DeviceTree blobs via a configuration table, these DTs are also able to be written to by a running UEFI Application */
/* TODO: Grab said blobs and translate them for XNU. */

/*!
 @function CDBDeviceTreeCreateFromFDT
 @abstract Sets up the DeviceTree using a provided DT.
 @param fdt Pointer to the Flattened Device Tree blob.
 */
CDBDeviceTreeRef CDBDeviceTreeCreateFromFDT(FlattenedDTHeader *fdt);

/*!
 @function CDBDeviceTreeCreateFromBinary
 @abstract Sets up the DeviceTree using a provided DT.
 @param Binary Pointer to the binary DeviceTree, eg: the way Apple stores them.
 */
CDBDeviceTreeRef CDBDeviceTreeCreateFromBinary(const UInt8 *Binary);

/*!
 @function CDBDeviceTreeCreate
 @abstract Creates a new DeviceTree, useful in the case of x86_64.
 */
CDBDeviceTreeRef CDBDeviceTreeCreate(void);

/*!
  @function CDBDTGetRootNode
  @abstract Gets the root node from the DeviceTree object
  @result Returns the root node
 */
CDBDTNodeRef CDBDTGetRootNode(CDBDeviceTreeRef DeviceTree);

/*!
  @function CDBDTGetNode
  @abstract Scans for the node within the allocated DeviceTree.
  @param nodePath Full path to the node requested, eg: /efi/platform or /chosen
  @param noNewNode Specifies if a node should be created or not if the node isn't found
  @result Returns the requested node if it could be found, otherwise returns NULL on failure.
 */
CDBDTNodeRef CDBDTGetNode(CDBDeviceTreeRef *DeviceTree, const char *nodePath, bool noNewNode);

/*!
  @function CDBDTGetProperty
  @abstract Gets the requested property from the node specified
  @param node The DT node to get the property from
  @param propertyName The name of the property to find
  @result Returns the requested property if it could be found, otherwise returns NULL.
 */
CDBDTPropertyRef CDBDTNodeGetProperty(CDBDTNodeRef node, const char *propertyName);

/*!
  @function CDBDTSetProperty
  @abstract Sets the requested property from the node specified
  @param node The DT node to set the property in
  @param propertyName The name of the property to set
  @param data The data to set in the property
  @param size The size of the data to set in the property
  @result Returns true if the operation was successful
 */
bool CDBDTNodeSetProperty(CDBDTNodeRef node, const char *propertyName, const UInt8 *data, UInt32 size);

/*!
  @function CDBDTPropertyGetValue
  @abstract Gets data from the specified DT property
  @param prop The DT property to get the data from
  @param valueOut The data from the property as a ptr ptr
  @param sizeOut The size of the data from the property
  @result Returns true if the operation was successful
 */
bool CDBDTPropertyGetValue(CDBDTPropertyRef prop, UInt8 **valueOut, UInt32 *sizeOut);

void CDBDTPrint(CDBDeviceTreeRef DeviceTree);
