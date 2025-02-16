// Copyright (C) 2025, Zormeister, All rights reserved. Licensed under the BSD 3-Clause License.

#pragma once
#include <Platform/Apple/APFS/Types.h>

// REFERENCE: https://developer.apple.com/support/downloads/Apple-File-System-Reference.pdf

// APFS operates as a Copy-on-Write Filesystem.
// This essentially means that every "write" is sent to a new object entry in either Phyiscal or Virtual objects

/*
 * Objects
 *
 * Objects are split into three categories:
 *  - Physical (on-disk object)
 *  - Ephemeral (in-memory object, which is written to the container upon unmount)
 *  - Virtual (on-disk object, looked up via the object map)
 */

/*
 * Physical Objects
 *
 * Physical objects are on-disk pieces of data. The way this is handled is that
 * o_oid is the block address of the associated piece of data, which means that
 * every physical "write" has a new OID.
 *
 * This is a simplified explaination, I highly reccomend reading the APFS Reference PDF.
 */

 /*
  * Ephemeral Objects
  *
  * Ephemeral objects are contained in-memory whilst the APFS container is mounted.
  * Periodically, the in-memory data should be written to the container as part of a
  * 'checkpoint'. 
  *
  * This is a simplified explaination, I highly reccomend reading the APFS Reference PDF.
  */

/*
 * Virtual Objects
 *
 * Virutal objects are stored on-disk, however there's a difference in how they're handled
 * from Physical objects, Virtual objects always have the same identifier as the file being modified,
 * Say I add some new text to a file, that file will have two copies, the original, and the newly modified version.
 * That file will have two entries under the same ID in the object map.
 *
 * In addition, the transaction identifier is used to lookup the object in the map, alongside other data such as the OID and point in time.
 *
 * This is a simplified explaination, I highly reccomend reading the APFS Reference PDF.
 */


/*
 * Object Identifiers
 *
 * Depending on the storage type, the OID means different things.
 *
 * For Physical objects, they are the logical block address of the data.
 * For Virtual and Ephemeral objects, it is a unique number, even across APFS Volumes.
 */
typedef uint64_t oid_t; // Object ID
typedef uint64_t xid_t; // Transaction ID

#define MAX_CKSUM_SIZE 8

struct obj_phys {
    uint8_t o_cksum[MAX_CKSUM_SIZE]; // Fletcher 64 Checksum
    oid_t o_oid;
    xid_t o_xid;
    uint32_t o_type;
    uint32_t o_subtype;
} typedef obj_phys_t;

enum {
    OID_INVALID = 0,
    OID_NX_SUPERBLOCK = 1,
    OID_RESERVED_COUNT = 1024,
};

enum {
    OBJECT_TYPE_MASK = 0x0000FFFF,
    OBJECT_TYPE_FLAGS_MASK = 0xFFFF0000,

    OBJ_STORAGETYPE_MASK = 0xC0000000,
    OBJECT_TYPE_FLAGS_DEFINED_MASK = 0xF8000000,

    OBJECT_TYPE_INVALID = 0,

    OBJECT_TYPE_NX_SUPERBLOCK = 1, // nx_superblock_t

    OBJECT_TYPE_BTREE = 2, // btree_node_phys_t
    OBJECT_TYPE_BTREE_NODE = 3, // btree_node_phys_t

    OBJECT_TYPE_SPACEMAN = 5, // spaceman_phys_t
    OBJECT_TYPE_SPACEMAN_CAB = 6, // cib_addr_block
    OBJECT_TYPE_SPACEMAN_CIB = 7, // chunk_info_block
    OBJECT_TYPE_SPACEMAN_BITMAP = 8, // No type - 'Free space bitmap used by the space manager'
    OBJECT_TYPE_SPACEMAN_FREE_QUEUE = 9, // 'A mapping from spaceman_free_queue_key_t to spaceman_free_queue_t'

    OBJECT_TYPE_EXTENT_LIST_TREE = 10, // Extents list tree - paddr_t to prange_t ??? - 'The keys are an offset into the logical start of the extent, and the value is the physical location where that data is stored'
    OBJECT_TYPE_OMAP = 11, // omap_phys_t if as the main type, omap_key_t to omap_val_t
    OBJECT_TYPE_CHECKPOINT_MAP = 12, // checkpoint_map_t

    OBJECT_TYPE_FS = 13, // apfs_superblock_t
    OBJECT_TYPE_FSTREE = 14, // j_key_t - FS Records
    OBJECT_TYPE_BLOCKREFTREE = 15, // j_phys_ext_key_t
    OBJECT_TYPE_SNAPMETATREE = 16, // 

    OBJECT_TYPE_NX_REAPER = 17,
    OBJECT_TYPE_NX_REAP_LIST = 18,
    OBJECT_TYPE_OMAP_SNAPSHOT = 19,
    OBJECT_TYPE_EFI_JUMPSTART = 20,
    OBJECT_TYPE_FUSION_MIDDLE_TREE = 21,
    OBJECT_TYPE_NX_FUSION_WBC = 22,
    OBJECT_TYPE_NX_FUSION_WBC_LIST = 23,
    OBJECT_TYPE_ER_STATE = 24,

    OBJECT_TYPE_GBITMAP = 25,
    OBJECT_TYPE_GBITMAP_TREE = 26,
    OBJECT_TYPE_GBITMAP_BLOCK = 27,

    OBJECT_TYPE_ER_RECOVERY_BLOCK = 28,
    OBJECT_TYPE_SNAP_META_EXT = 29,
    OBJECT_TYPE_INTEGRITY_META = 30,
    OBJECT_TYPE_FEXT_TREE = 31,
    OBJECT_TYPE_RESERVED_20 = 32,

    OBJECT_TYPE_TEST = 255,

    OBJECT_TYPE_CONTAINER_KEYBAG = 'keys',
    OBJECT_TYPE_VOLUME_KEYBAG = 'recs',
    OBJECT_TYPE_MEDIA_KEYBAG = 'mkey'
};

