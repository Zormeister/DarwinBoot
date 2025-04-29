// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/EFI/Types.h>

#define EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID \
  {0x9042a9de,0x23dc,0x4a38,\
    {0x96,0xfb,0x7a,0xde,0xd0,0x80,0x51,0x6a}}

struct {
    UInt32 RedMask;
    UInt32 GreenMask;
    UInt32 BlueMask;
    UInt32 ReservedMask; 
} typedef EFI_PIXEL_BITMASK;

typedef enum {
    PixelRedGreenBlueReserved8BitPerColor,
    PixelBlueGreenRedReserved8BitPerColor,
    PixelBitMask,
    PixelBltOnly,
    PixelFormatMax
} EFI_GRAPHICS_PIXEL_FORMAT;

struct {
    UInt32 Version;
    UInt32 Width;
    UInt32 Height;
    EFI_GRAPHICS_PIXEL_FORMAT Format;
    EFI_PIXEL_BITMASK Bitmask;
    UInt32 PixelsPerScanLine;
} typedef EFI_GRAPHICS_OUTPUT_MODE_INFORMATION;

struct {
    UInt32 MaxMode;
    UInt32 Mode;
    EFI_GRAPHICS_OUTPUT_MODE_INFORMATION *ModeInfo;
    UIntN SizeOfModeInfo;
    EFI_PHYSICAL_ADDRESS FBBaseAddress;
    UIntN FramebufferSize;
} typedef EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE;

typedef struct _EFI_GRAPHICS_OUTPUT_PROTOCOL EFI_GRAPHICS_OUTPUT_PROTOCOL;

struct {
    UInt8 Red;
    UInt8 Green;
    UInt8 Blue;
    UInt8 Rsvd;
} typedef EFI_GRAPHICS_OUTPUT_BLT_PIXEL;

typedef enum {
    EfiBltVideoFill,
    EfiBltVideoToBltBuffer,
    EfiBltBufferToVideo,
    EfiBltVideoToVideo,
    EfiGraphicsOutputBltOperationMax
} EFI_GRAPHICS_OUTPUT_BLT_OPERATION;   

struct _EFI_GRAPHICS_OUTPUT_PROTOCOL {
    EFI_STATUS (*QueryMode)(EFI_GRAPHICS_OUTPUT_PROTOCOL *This, UInt32 ModeNumber, UIntN *SizeOfModeInfo, EFI_GRAPHICS_OUTPUT_MODE_INFORMATION **ModeInfo);
    EFI_STATUS (*SetMode)(EFI_GRAPHICS_OUTPUT_PROTOCOL *This, UInt32 ModeNumber);
    EFI_STATUS (*Blt)(EFI_GRAPHICS_OUTPUT_PROTOCOL *This, EFI_GRAPHICS_OUTPUT_BLT_PIXEL *BltBuffer, EFI_GRAPHICS_OUTPUT_BLT_OPERATION BltOperation,
                        UIntN SourceX, UIntN SourceY, UIntN DestinationX, UIntN DestinationY, UIntN Width, UIntN Height, UIntN Delta);
    EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE *Mode;
};
