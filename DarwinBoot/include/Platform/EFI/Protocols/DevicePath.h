// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/EFI/Types.h>

#define EFI_DEVICE_PATH_PROTOCOL_GUID \
  {0x09576e91,0x6d3f,0x11d2,\
    {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

enum {
    EFI_DEVICE_PATH_TYPE_HARDWARE = 1,
    EFI_DEVICE_PATH_TYPE_ACPI,
    EFI_DEVICE_PATH_TYPE_MESSAGING_DEVICE,
    EFI_DEVICE_PATH_TYPE_MEDIA_DEVICE,
    EFI_DEVICE_PATH_TYPE_BIOS_BOOT_SPEC,
};

enum {
    EFI_HARDWARE_PATH_SUBTYPE_PCI = 1,
    EFI_HARDWARE_PATH_SUBTYPE_PCCARD = 2,
    EFI_HARDWARE_PATH_SUBTYPE_MEMORYMAPPED = 3,
    EFI_HARDWARE_PATH_SUBTYPE_VENDOR = 4,
    EFI_HARDWARE_PATH_SUBTYPE_CONTROLLER = 5,
    EFI_HARDWARE_PATH_SUBTYPE_BMC = 6,
};

#define EFI_PNP_ID(ID) (UINT32)(((ID) << 16) | 0x41D0)
#define EISA_PNP_ID(ID) EFI_PNP_ID(ID)

enum {
    EFI_ACPI_PATH_SUBTYPE_DEVICE = 1,
    EFI_ACPI_PATH_SUBTYPE_EXTENDED_DEVICE = 2,
    EFI_ACPI_PATH_SUBTYPE_ADR = 3,
    EFI_ACPI_PATH_SUBTYPE_NVDIMM = 4,
};

struct {
    UInt8 Type;
    UInt8 SubType;
    UInt8 Length[2];
} typedef EFI_DEVICE_PATH_PROTOCOL;

struct {
    UInt8 Type;
    UInt8 SubType;
    UInt8 Length[2];
    UInt8 PCIFunction;
    UInt8 PCIDevice;
} typedef EFI_DEVICE_PATH_PCI_PROTOCOL;

struct {
    UInt8 Type;
    UInt8 SubType;
    UInt8 Length[2];
    char HID[4];
    char UID[4];
} typedef EFI_DEVICE_PATH_ACPI_PROTOCOL;

struct {
    UInt8 Type;
    UInt8 SubType;
    UInt8 Length[2];
    char HID[4];
    char UID[4];
    char CID[4];
    char STRS[]; /* bruh */
} typedef EFI_DEVICE_PATH_EXT_ACPI_PROTOCOL;

struct {
    UInt8 Type;
    UInt8 SubType;
    UInt8 Length[2];
    char ADR[4];
    char AdditionalADR[];
} typedef EFI_DEVICE_PATH_ACPI_ADR_PROTOCOL;

enum {
    EFI_MESSAGED_PATH_SUBTYPE_ATAPI = 1,
    EFI_MESSAGED_PATH_SUBTYPE_SCSI = 2,
    EFI_MESSAGED_PATH_SUBTYPE_FIBRE_CHANNEL = 3,
    EFI_MESSAGED_PATH_SUBTYPE_1394 = 4,
    EFI_MESSAGED_PATH_SUBTYPE_USB = 5,
};

struct {
    UInt8 Type;
    UInt8 SubType;
    UInt8 Length[2];
    UInt8 PrimarySecondary;
    UInt8 SlaveMaster;
    UInt16 LogicalUnitNumber;
} typedef EFI_DEVICE_PATH_MESSAGED_ATAPI_PROTOCOL;

struct {
    UInt8 Type;
    UInt8 SubType;
    UInt8 Length[2];
    UInt16 TargetID;
    UInt16 LogicalUnitNumber;
} typedef EFI_DEVICE_PATH_MESSAGED_SCSI_PROTOCOL;

struct {
    UInt8 Type;
    UInt8 SubType;
    UInt8 Length[2];
    UInt32 Reserved;
    char WorldWideName[8];
    char LogicalUnitNumber[8];
} typedef EFI_DEVICE_PATH_MESSAGED_FIBRE_CHANNEL_PROTOCOL;

struct {
    UInt8 Type;
    UInt8 SubType;
    UInt8 Length[2];
    UInt32 Reserved;
    char WorldWideName[8];
    char LogicalUnitNumber[8];
} typedef EFI_DEVICE_PATH_MESSAGED_FIBRE_CHANNEL_EX_PROTOCOL;

struct {
    UInt8 Type;
    UInt8 SubType;
    UInt8 Length[2];
    UInt32 Reserved;
    EFI_GUID GUID;
} typedef EFI_DEVICE_PATH_MESSAGED_1394_PROTOCOL;

struct {
    UInt8 Type;
    UInt8 SubType;
    UInt8 Length[2];
    UInt8 ParentPortNum;
    UInt8 InterfaceNum;
} typedef EFI_DEVICE_PATH_MESSAGED_USB_PROTOCOL;

/* I genuinely cannot be bothered defining the rest of the Messaged types. */


/* Media Paths. Thank god. */

enum {
    EFI_MEDIA_PATH_SUBTYPE_HARD_DRIVE = 1,
    EFI_MEDIA_PATH_SUBTYPE_CDROM = 2,
    EFI_MEDIA_PATH_SUBTYPE_VENDOR = 3,
    EFI_MEDIA_PATH_SUBTYPE_FILE_PATH = 4,
};

struct {
    UInt8 Type;
    UInt8 SubType;
    UInt8 Length[2];
    UInt32 PartitionNumber;
    EFI_LBA StartingLBA;
    UInt64 PartitionSize;
    char PartitionSignature[16];
    UInt8 PartitionFormat;
    UInt8 SignatureType;
} typedef EFI_DEVICE_PATH_MEDIA_HD_PROTOCOL;

struct {
    UInt8 Type;
    UInt8 SubType;
    UInt8 Length[2];
    UInt32 BootEntry;
    EFI_PHYSICAL_ADDRESS PartitionStart;
    UInt64 PartitionSize;
} typedef EFI_DEVICE_PATH_MEDIA_CDROM_PROTOCOL;

struct {
    UInt8 Type;
    UInt8 SubType;
    UInt8 Length[2];
    EFI_GUID VendorGUID;
    uint8_t VendorData[];
} typedef EFI_DEVICE_PATH_MEDIA_VENDOR_PROTOCOL;

struct {
    UInt8 Type;
    UInt8 SubType;
    UInt8 Length[2];
    wchar_t Path[];
} typedef EFI_DEVICE_PATH_MEDIA_FILE_PATH_PROTOCOL;
