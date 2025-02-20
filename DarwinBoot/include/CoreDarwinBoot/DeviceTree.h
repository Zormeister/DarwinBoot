// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include "CDBBasicTypes.h"

typedef struct _CDBDeviceTree *CDBDeviceTree;
typedef struct _CDBDTNode *CDBDTNode;
typedef struct _CDBDTProperty *CDBDTProperty;

enum DTDataType {
    Structure = 1,
    Integer8,
    Integer16,
    Integer32,
    Integer64,
    String,
    Any,
};

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

/*!
  @function CDBCreateDeviceTree
  @abstract Allocates a CDBDeviceTree and sets up the root node, which is stored in Platform code as a global variable.
  @result Returns true if the operation was successful
 */
bool CDBCreateDeviceTree(void);

/* FDT */

#define FDT_HEADER_MAGIC 0xDEADF00D

struct _FDTHeader {
    UInt32 Magic;
    UInt32 TotalSize;
    UInt32 DTStructOffset;
    UInt32 DTStringsOffset;
    UInt32 MemReservationMapOffset;
    UInt32 Version;
    UInt32 LastCompatibleVersion;
    UInt32 BootCPUPhysID;
    UInt32 DTStringsSize;
    UInt32 DTStructureSize;
} typedef FDTHeader;

struct {
    UInt64 Base;
    UInt64 Size;
} typedef FDTReservedMemEntry;

/*!
 @function CDBCreateDeviceTreeWithFDT
 @abstract Sets up the DeviceTree using a provided DT.
 @param fdt Pointer to the Flattened Device Tree blob.
 */
bool CDBCreateDeviceTreeWithFDT(FDTHeader *fdt);

/*!
  @function CDBDTGetRootNode
  @abstract Gets the root node from the DeviceTree object
  @result Returns the root node
 */
CDBDTNode CDBDTGetRootNode(void);

/*!
  @function CDBDTGetNode
  @abstract Scans for the node within the allocated DeviceTree. 
  @param nodePath Full path to the node requested, eg: /efi/platform or /chosen 
  @param noNewNode Specifies if a node should be created or not if the node isn't found
  @result Returns the requested node if it could be found, otherwise returns NULL on failure.
 */
CDBDTNode CDBDTGetNode(const char *nodePath, bool noNewNode);

/*!
  @function CDBDTGetProperty
  @abstract Gets the requested property from the node specified
  @param node The DT node to get the property from
  @param propertyName The name of the property to find
  @result Returns the requested property if it could be found, otherwise returns NULL.
 */
CDBDTProperty CDBDTGetProperty(CDBDTNode node, const char *propertyName);

/*!
  @function CDBDTSetProperty
  @abstract Sets the requested property from the node specified
  @param node The DT node to set the property in
  @param propertyName The name of the property to set
  @param data The data to set in the property
  @param size The size of the data to set in the property
  @result Returns true if the operation was successful
 */
bool CDBDTSetProperty(CDBDTNode node, const char *propertyName, const UInt8 *data, UInt32 size);

/*!
  @function CDBDTPropertyGetValue
  @abstract Gets data from the specified DT property
  @param prop The DT property to get the data from
  @param valueOut The data from the property as a ptr ptr
  @param sizeOut The size of the data from the property
  @result Returns true if the operation was successful
 */
bool CDBDTPropertyGetValue(CDBDTProperty prop, UInt8 **valueOut, UInt32 *sizeOut);
