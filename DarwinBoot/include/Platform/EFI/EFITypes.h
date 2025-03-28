// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

/* LAST SYNCED: UEFI 2.11 */

// Conditionals.
#if defined (__x86_64__) || defined (__arm64__)
typedef UInt32 UIntN;
#elif defined (__i386__) || defined (__arm__)
typedef UInt32 UIntN;
#endif

typedef void * EFI_HANDLE;
typedef void * EFI_EVENT;

typedef void (*EFI_EVENT_NOTIFY)(EFI_EVENT *Event, void *Context);

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

#define TPL_APPLICATION 4
#define TPL_CALLBACK 8
#define TPL_NOTIFY 16
#define TPL_HIGH_LEVEL 31

typedef UIntN EFI_PHYSICAL_ADDRESS;
typedef UIntN EFI_VIRTUAL_ADDRESS;

enum EFI_STATUS_CODES {
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

typedef enum {
    TimerCancel,
    TimerPeriodic,
    TimerRelative,
} EFI_TIMER_DELAY;

typedef enum {
    EFI_NATIVE_INTERFACE
} EFI_INTERFACE_TYPE;

typedef enum {
    AllHandles,
    ByRegisterNotify,
    ByProtocol
} EFI_LOCATE_SEARCH_TYPE;

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

struct {
    UInt16 Year;
    UInt8 Month;
    UInt8 Day;
    UInt8 Hour;
    UInt8 Minute;
    UInt8 Second;
    UInt8 Padding;
    UInt32 Nanosecond;
    SInt32 TimeZone;
    UInt8 Daylight;
    UInt8 Padding2;
} typedef EFI_TIME;

#define EFI_TIME_ADJUST_DAYLIGHT 0x1
#define EFI_TIME_IN_DAYLIGHT 0x2

#define EFI_UNSPECIFIED_TIMEZONE 0x7FF

struct {
    UInt32 Resolution;
    UInt32 Accuracy;
    bool SetsToZero;
} typedef EFI_TIME_CAPABILITIES;