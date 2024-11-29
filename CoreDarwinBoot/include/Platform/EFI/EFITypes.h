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
#include <CoreDarwinBoot/CDBBasicTypes.h>

/* LAST SYNCED: UEFI 2.10 */

#if PLATFORM_EFI == 1

typedef void * EFI_HANDLE;
typedef void * EFI_EVENT;

#define EVT_TIMER                            0x80000000
#define EVT_RUNTIME                          0x40000000

#define EVT_NOTIFY_WAIT                      0x00000100
#define EVT_NOTIFY_SIGNAL                    0x00000200

#define EVT_SIGNAL_EXIT_BOOT_SERVICES        0x00000201
#define EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE    0x60000202

#define EFI_HIGH_BIT (0x80000000)

#define EFI_ERROR(code) (EFI_HIGH_BIT | (code))

/* 128-bit? */
typedef UInt64 EFI_STATUS;
typedef UInt64 EFI_LBA;
typedef UInt64 EFI_TPL;

typedef UInt64 EFI_PHYSICAL_ADDRESS;
typedef UInt64 EFI_VIRTUAL_ADDRESS;

enum EFI_STATUS_CODES : EFI_STATUS {
    EFI_SUCCESS = 0,
    EFI_LOAD_ERROR = EFI_ERROR(1),
    EFI_INVALID_PARAMETER = EFI_ERROR(2),
    EFI_UNSUPPORTED = EFI_ERROR(3),
    EFI_BAD_BUFFER_SIZE = EFI_ERROR(4),
    EFI_BUFFER_TOO_SMALL = EFI_ERROR(5),
    EFI_NOT_READY = EFI_ERROR(6),
    EFI_DEVICE_ERROR = EFI_ERROR(7),
    EFI_WRITE_PROTECTED = EFI_ERROR(8),
    EFI_OUT_OF_RESOURCES = EFI_ERROR(9),
    EFI_VOLUME_CORRUPTED = EFI_ERROR(10),
    EFI_VOLUME_FULL = EFI_ERROR(11),
    EFI_NO_MEDIA = EFI_ERROR(12),
    EFI_MEDIA_CHANGED = EFI_ERROR(13),
    EFI_NOT_FOUND = EFI_ERROR(14),
    EFI_ACCESS_DENIED = EFI_ERROR(15),
    EFI_NO_RESPONSE = EFI_ERROR(16),
    EFI_NO_MAPPING = EFI_ERROR(17),
    EFI_TIMEOUT = EFI_ERROR(18),
    EFI_NOT_STARTED = EFI_ERROR(19),
    EFI_ALREADY_STARTED = EFI_ERROR(20),
    EFI_ABORTED = EFI_ERROR(21),
    EFI_ICMP_ERROR = EFI_ERROR(22),
    EFI_TFTP_ERROR = EFI_ERROR(23),
    EFI_PROTOCOL_ERROR = EFI_ERROR(24),
    EFI_INCOMPATIBLE_VERSION = EFI_ERROR(25),
    EFI_SECURITY_VIOLATION = EFI_ERROR(26),
    EFI_CRC_ERROR = EFI_ERROR(27),
    EFI_END_OF_MEDIA = EFI_ERROR(28),
    EFI_END_OF_FILE = EFI_ERROR(31),
    EFI_INVALID_LANGUAGE = EFI_ERROR(32),
    EFI_COMPROMISED_DATA = EFI_ERROR(33),
    EFI_IP_ADDRESS_CONFLICT = EFI_ERROR(34),
    EFI_HTTP_ERROR = EFI_ERROR(35),
    EFI_WARN_UNKNOWN_GLYPH = 1,
    EFI_WARN_DELETE_FAILURE = 2,
    EFI_WARN_WRITE_FAILURE = 3,
    EFI_WARN_BUFFER_TOO_SMALL = 4,
    EFI_WARN_STALE_DATA = 5,
    EFI_WARN_FILE_SYSTEM = 6,
    EFI_WARN_RESET_REQUIRED = 7,
};

struct {
    UInt8 Address[32];
} typedef EFI_MAC_ADDRESS;

struct {
    UInt8 Address[4];
} typedef EFI_IPv4_ADDRESS;

struct {
    UInt8 Address[16];
} typedef EFI_IPv6_ADDRESS;

union {
    EFI_IPv4_ADDRESS IPv4;
    EFI_IPv6_ADDRESS IPv6;
} typedef EFI_IP_ADDRESS;

struct {
    UInt32 Data1;
    UInt16 Data2;
    UInt16 Data3;
    UInt8 Data4[8];
} typedef EFI_GUID;

struct {
    UInt16 ScanCode;
    SInt16 UnicodeChar;
} typedef EFI_INPUT_KEY;

struct _EFI_TABLE_HEADER {
    UInt64 Signature;
    UInt32 Revision;
    UInt32 HeaderSize;
    UInt32 CRC32;
    UInt32 Reserved;
};
typedef struct _EFI_TABLE_HEADER EFI_TABLE_HEADER;

#pragma mark EFI_SIMPLE_TEXT_INPUT_PROTOCOL

#define EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID \
 {0x387477c1,0x69c7,0x11d2,\
  {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

typedef struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
    /* Reset - This: IN, ExtentedVerification: IN */
    EFI_STATUS (*Reset)(EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This, bool ExtendedVerification);
    /* Reset - This: IN, Key: OUT */
    EFI_STATUS (*ReadKeyStroke)(EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This, EFI_INPUT_KEY *Key);
    EFI_EVENT WaitForKey;
};

#pragma mark EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL

struct {
    SInt32 MaxMode;
    SInt32 Mode;
    SInt32 Attribute;
    SInt32 CursorColumn;
    SInt32 CursorRow;
    bool CursorVisible;
} typedef SIMPLE_TEXT_OUTPUT_MODE;

#define EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID \
 {0x387477c2,0x69c7,0x11d2,\
  {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
    EFI_STATUS (*Reset)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, bool ExtendedVerification);
    EFI_STATUS (*OutputString)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, wchar_t *String);
    EFI_STATUS (*TestString)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, wchar_t *String);
    EFI_STATUS (*QueryMode)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, UInt32 ModeNumber, UInt32 *Columns, UInt32 *Rows);
    EFI_STATUS (*SetMode)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, UInt32 ModeNumber);
    EFI_STATUS (*SetAttribute)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, UInt32 Attribute);
    EFI_STATUS (*ClearScreen)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This);
    EFI_STATUS (*EnableCursor)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This);
    SIMPLE_TEXT_OUTPUT_MODE *Mode;
};

/* Attributes */
#define EFI_BLACK 0x0
#define EFI_BLUE 0x1
#define EFI_GREEN 0x2
#define EFI_CYAN 0x3
#define EFI_RED 0x4
#define EFI_MAGENTA 0x5
#define EFI_BROWN 0x6
#define EFI_LIGHTGRAY 0x7
#define EFI_BRIGHT 0x8
#define EFI_DARKGRAY (EFI_BLACK | EFI_BRIGHT)
#define EFI_LIGHTBLUE 0x9
#define EFI_LIGHTGREEN 0xA
#define EFI_LIGHTCYAN 0xB
#define EFI_LIGHTRED 0xC
#define EFI_LIGHTMAGENTA 0xD
#define EFI_YELLOW 0xE
#define EFI_WHITE 0xF

#define EFI_BACKGROUND_BLACK 0x00
#define EFI_BACKGROUND_BLUE 0x10
#define EFI_BACKGROUND_GREEN 0x20
#define EFI_BACKGROUND_CYAN 0x30
#define EFI_BACKGROUND_RED 0x40
#define EFI_BACKGROUND_MAGENTA 0x50
#define EFI_BACKGROUND_BROWN 0x60
#define EFI_BACKGROUND_LIGHTGRAY 0x70

/* Unicode drawing characters */
#define BOXDRAW_HORIZONTAL 0x2500
#define BOXDRAW_VERTICAL 0x2502
#define BOXDRAW_DOWN_RIGHT 0x250C
#define BOXDRAW_DOWN_LEFT 0x2510
#define BOXDRAW_UP_RIGHT 0x2514
#define BOXDRAW_UP_LEFT 0x2518
#define BOXDRAW_VERTICAL_RIGHT 0x251C
#define BOXDRAW_VERTICAL_LEFT 0x2524
#define BOXDRAW_DOWN_HORIZONTAL 0x252C
#define BOXDRAW_UP_HORIZONTAL 0x2534
#define BOXDRAW_VERTICAL_HORIZONTAL 0x253C
#define BOXDRAW_DOUBLE_HORIZONTAL 0x2550
#define BOXDRAW_DOUBLE_VERTICAL 0x2551
#define BOXDRAW_DOWN_RIGHT_DOUBLE 0x2552
#define BOXDRAW_DOWN_DOUBLE_RIGHT 0x2553
#define BOXDRAW_DOUBLE_DOWN_RIGHT 0x2554
#define BOXDRAW_DOWN_LEFT_DOUBLE 0x2555
#define BOXDRAW_DOWN_DOUBLE_LEFT 0x2556
#define BOXDRAW_DOUBLE_DOWN_LEFT 0x2557
#define BOXDRAW_UP_RIGHT_DOUBLE 0x2558
#define BOXDRAW_UP_DOUBLE_RIGHT 0x2559
#define BOXDRAW_DOUBLE_UP_RIGHT 0x255A
#define BOXDRAW_UP_LEFT_DOUBLE 0x255B
#define BOXDRAW_UP_DOUBLE_LEFT 0x255C
#define BOXDRAW_DOUBLE_UP_LEFT 0x255D
#define BOXDRAW_VERTICAL_RIGHT_DOUBLE 0x255E
#define BOXDRAW_VERTICAL_DOUBLE_RIGHT 0x255F
#define BOXDRAW_DOUBLE_VERTICAL_RIGHT 0x2560
#define BOXDRAW_VERTICAL_LEFT_DOUBLE 0x2561
#define BOXDRAW_VERTICAL_DOUBLE_LEFT 0x2562
#define BOXDRAW_DOUBLE_VERTICAL_LEFT 0x2563
#define BOXDRAW_DOWN_HORIZONTAL_DOUBLE 0x2564
#define BOXDRAW_DOWN_DOUBLE_HORIZONTAL 0x2565
#define BOXDRAW_DOUBLE_DOWN_HORIZONTAL 0x2566
#define BOXDRAW_UP_HORIZONTAL_DOUBLE 0x2567
#define BOXDRAW_UP_DOUBLE_HORIZONTAL 0x2568
#define BOXDRAW_DOUBLE_UP_HORIZONTAL 0x2569
#define BOXDRAW_VERTICAL_HORIZONTAL_DOUBLE 0x256A
#define BOXDRAW_VERTICAL_DOUBLE_HORIZONTAL 0x256B
#define BOXDRAW_DOUBLE_VERTICAL_HORIZONTAL 0x256C

#define BLOCKELEMENT_FULL_BLOCK        0x2588
#define BLOCKELEMENT_LIGHT_SHADE       0x2591

#define GEOMETRICSHAPE_UP_TRIANGLE 0x25B2
#define GEOMETRICSHAPE_RIGHT_TRIANGLE 0x25BA
#define GEOMETRICSHAPE_DOWN_TRIANGLE 0x25BC
#define GEOMETRICSHAPE_LEFT_TRIANGLE 0x25C4

#define ARROW_UP 0x2191
#define ARROW_DOWN 0x2193

#pragma mark EFI_CONFIGURATION_TABLE

typedef struct _EFI_CONFIGURATION_TABLE EFI_CONFIGURATION_TABLE;

struct _EFI_CONFIGURATION_TABLE {
    EFI_GUID VendorGuid;
    void *VendorTable;
};

#pragma mark EFI_ALLOCATE_TYPE

typedef enum {
   AllocateAnyPages,
   AllocateMaxAddress,
   AllocateAddress,
   MaxAllocateType
} EFI_ALLOCATE_TYPE;

#pragma mark EFI_MEMORY_TYPE

typedef enum {
   EfiReservedMemoryType,
   EfiLoaderCode,
   EfiLoaderData,
   EfiBootServicesCode,
   EfiBootServicesData,
   EfiRuntimeServicesCode,
   EfiRuntimeServicesData,
   EfiConventionalMemory,
   EfiUnusableMemory,
   EfiACPIReclaimMemory,
   EfiACPIMemoryNVS,
   EfiMemoryMappedIO,
   EfiMemoryMappedIOPortSpace,
   EfiPalCode,
   EfiPersistentMemory,
   EfiUnacceptedMemoryType,
   EfiMaxMemoryType
} EFI_MEMORY_TYPE;

#pragma mark EFI_MEMORY_DESCRIPTOR

struct {
    UInt32 Type;
    EFI_PHYSICAL_ADDRESS PhysicalStart;
    EFI_VIRTUAL_ADDRESS VirtualStart;
    UInt64 NumberOfPages;
    UInt64 Attribute;
} typedef EFI_MEMORY_DESCRIPTOR;

/* Cache Attrs */
#define EFI_MEMORY_UC (1 << 0)
#define EFI_MEMORY_WC (1 << 1)
#define EFI_MEMORY_WT (1 << 2)
#define EFI_MEMORY_WB (1 << 3)
#define EFI_MEMORY_UCE (1 << 4)
/* Memory Prot. Attrs*/
#define EFI_MEMORY_WP (1 << 12)
#define EFI_MEMORY_RP (1 << 13)
#define EFI_MEMORY_XP (1 << 14)
#define EFI_MEMORY_NV (1 << 15)
#define EFI_MEMORY_MORE_RELIABLE (1 << 16)
#define EFI_MEMORY_RO (1 << 17)
#define EFI_MEMORY_SP (1 << 18)
#define EFI_MEMORY_CPU_CRYPTO (1 << 19)
#define EFI_MEMORY_RUNTIME (1 << 63)
#define EFI_MEMORY_ISA_VALID (1 << 62)
#define EFI_MEMORY_ISA_MASK (1 << 44) | (1 << 45) | (1 << 46) | (1 << 47) | (1 << 48) | (1 << 49) | (1 << 50) | (1 << 51) | (1 << 52) | (1 << 53) | (1 << 54) | (1 << 55) | (1 << 56) | (1 << 57) | (1 << 58) | (1 << 59)

#pragma mark EFI_MEMORY_ATTRIBUTES_TABLE

#define EFI_MEMORY_ATTRIBUTES_TABLE_GUID \
  {0xdcfa911d, 0x26eb, 0x469f, \
    {0xa2, 0x20, 0x38, 0xb7, 0xdc, 0x46, 0x12, 0x20}}

struct {
    UInt32 Version;
    UInt32 NumberOfEntries;
    UInt32 DescriptorSize;
    UInt32 Flags;
    EFI_MEMORY_DESCRIPTOR Descriptors[];
} typedef EFI_MEMORY_ATTRIBUTES_TABLE;

#define EFI_MEMORY_ATTRIBUTES_FLAGS_RT_FORWARD_CONTROL_FLOW_GUARD  0x1

/* UEFI apps have R/W access to the FDT */
#define EFI_DTB_TABLE_GUID \
  {0xb1b621d5, 0xf19c, 0x41a5, \
    {0x83, 0x0b, 0xd9, 0x15, 0x2c, 0x69, 0xaa, 0xe0}}

#pragma mark EFI_SYSTEM_TABLE

#define EFI_SYSTEM_TABLE_SIGNATURE 0x5453595320494249
#define EFI_2_100_SYSTEM_TABLE_REVISION ((2<<16) | (100))
#define EFI_2_90_SYSTEM_TABLE_REVISION ((2<<16) | (90))
#define EFI_2_80_SYSTEM_TABLE_REVISION ((2<<16) | (80))
#define EFI_2_70_SYSTEM_TABLE_REVISION ((2<<16) | (70))
#define EFI_2_60_SYSTEM_TABLE_REVISION ((2<<16) | (60))
#define EFI_2_50_SYSTEM_TABLE_REVISION ((2<<16) | (50))
#define EFI_2_40_SYSTEM_TABLE_REVISION ((2<<16) | (40))
#define EFI_2_31_SYSTEM_TABLE_REVISION ((2<<16) | (31))
#define EFI_2_30_SYSTEM_TABLE_REVISION ((2<<16) | (30))
#define EFI_2_20_SYSTEM_TABLE_REVISION ((2<<16) | (20))
#define EFI_2_10_SYSTEM_TABLE_REVISION ((2<<16) | (10))
#define EFI_2_00_SYSTEM_TABLE_REVISION ((2<<16) | (00))
#define EFI_1_10_SYSTEM_TABLE_REVISION ((1<<16) | (10))
#define EFI_1_02_SYSTEM_TABLE_REVISION ((1<<16) | (02))
#define EFI_SPECIFICATION_VERSION EFI_SYSTEM_TABLE_REVISION
#define EFI_SYSTEM_TABLE_REVISION EFI_2_100_SYSTEM_TABLE_REVISION

typedef struct _EFI_BOOT_SERVICES EFI_BOOT_SERVICES;
typedef struct _EFI_RUNTIME_SERVICES EFI_RUNTIME_SERVICES;

// TODO: see if wchar_t is actually defined
struct _EFI_SYSTEM_TABLE {
    EFI_TABLE_HEADER Header;
    wchar_t * FirmwareVendor;
    UInt32 FirmwareRevision;
    EFI_HANDLE ConInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL *ConIn;
    EFI_HANDLE ConOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
    EFI_HANDLE StandardErrorHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *StdErr;
    EFI_RUNTIME_SERVICES *RuntimeServices;
    EFI_BOOT_SERVICES *BootServices;
    UInt32 NumberOfTableEntries;
    EFI_CONFIGURATION_TABLE *ConfigurationTables;
};

typedef struct _EFI_SYSTEM_TABLE EFI_SYSTEM_TABLE;

#pragma mark EFI_BOOT_SERVICES

#define EFI_BOOT_SERVICES_SIGNATURE 0x56524553544f4f42
#define EFI_BOOT_SERVICES_REVISION EFI_SPECIFICATION_VERSION

struct _EFI_BOOT_SERVICES {
    EFI_TABLE_HEADER Header;
    
};

#define EFI_RUNTIME_SERVICES_SIGNATURE 0x56524553544e5552
#define EFI_RUNTIME_SERVICES_REVISION EFI_SPECIFICATION_VERSION


#define EFI_LOADED_IMAGE_PROTOCOL_GUID \
  {0x5B1B31A1,0x9562,0x11D2,\
    {0x8E,0x3F,0x00,0xA0,0xC9,0x69,0x72,0x3B}}

#define EFI_LOADED_IMAGE_PROTOCOL_REVISION 0x1000

typedef EFI_STATUS (*EFI_IMAGE_UNLOAD)(EFI_HANDLE *ImageHandle);

struct _EFI_LOADED_IMAGE_PROTOCOL {
    uint32_t Revision;
    EFI_HANDLE ParentHandle;

};

#endif /* EFI_PLATFORM == 1 */
