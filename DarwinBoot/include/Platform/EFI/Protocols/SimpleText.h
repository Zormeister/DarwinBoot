// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_SIMPLETEXT_H__
#define __PLATFORM_EFI_PROTOCOLS_SIMPLETEXT_H__

#include <Platform/EFI/Types.h>

#pragma mark EFI_SIMPLE_TEXT_INPUT_PROTOCOL

#define EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID \
    { 0x387477c1, 0x69c7, 0x11d2,           \
        { 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } }

extern EFI_GUID gEfiSimpleTextInputProtocolGuid;

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
    { 0x387477c2, 0x69c7, 0x11d2,            \
        { 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } }

extern EFI_GUID gEfiSimpleTextOutputProtocolGuid;

typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
    EFI_STATUS (*Reset)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, bool ExtendedVerification);
    EFI_STATUS (*OutputString)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, wchar_t *String);
    EFI_STATUS (*TestString)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, wchar_t *String);
    EFI_STATUS (*QueryMode)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, UInt32 ModeNumber, UInt32 *Columns, UInt32 *Rows);
    EFI_STATUS (*SetMode)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, UInt32 ModeNumber);
    EFI_STATUS (*SetAttribute)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, UInt32 Attribute);
    EFI_STATUS (*ClearScreen)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This);
    EFI_STATUS (*SetCursorPosition)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, UIntN Column, UIntN Row);
    EFI_STATUS (*EnableCursor)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This);
    SIMPLE_TEXT_OUTPUT_MODE *Mode;
};

/* Attributes */
#define EFI_BLACK        0x0
#define EFI_BLUE         0x1
#define EFI_GREEN        0x2
#define EFI_CYAN         0x3
#define EFI_RED          0x4
#define EFI_MAGENTA      0x5
#define EFI_BROWN        0x6
#define EFI_LIGHTGRAY    0x7
#define EFI_BRIGHT       0x8
#define EFI_DARKGRAY     (EFI_BLACK | EFI_BRIGHT)
#define EFI_LIGHTBLUE    0x9
#define EFI_LIGHTGREEN   0xA
#define EFI_LIGHTCYAN    0xB
#define EFI_LIGHTRED     0xC
#define EFI_LIGHTMAGENTA 0xD
#define EFI_YELLOW       0xE
#define EFI_WHITE        0xF

#define EFI_BACKGROUND_BLACK     0x00
#define EFI_BACKGROUND_BLUE      0x10
#define EFI_BACKGROUND_GREEN     0x20
#define EFI_BACKGROUND_CYAN      0x30
#define EFI_BACKGROUND_RED       0x40
#define EFI_BACKGROUND_MAGENTA   0x50
#define EFI_BACKGROUND_BROWN     0x60
#define EFI_BACKGROUND_LIGHTGRAY 0x70

/* Unicode drawing characters */
#define BOXDRAW_HORIZONTAL                 0x2500
#define BOXDRAW_VERTICAL                   0x2502
#define BOXDRAW_DOWN_RIGHT                 0x250C
#define BOXDRAW_DOWN_LEFT                  0x2510
#define BOXDRAW_UP_RIGHT                   0x2514
#define BOXDRAW_UP_LEFT                    0x2518
#define BOXDRAW_VERTICAL_RIGHT             0x251C
#define BOXDRAW_VERTICAL_LEFT              0x2524
#define BOXDRAW_DOWN_HORIZONTAL            0x252C
#define BOXDRAW_UP_HORIZONTAL              0x2534
#define BOXDRAW_VERTICAL_HORIZONTAL        0x253C
#define BOXDRAW_DOUBLE_HORIZONTAL          0x2550
#define BOXDRAW_DOUBLE_VERTICAL            0x2551
#define BOXDRAW_DOWN_RIGHT_DOUBLE          0x2552
#define BOXDRAW_DOWN_DOUBLE_RIGHT          0x2553
#define BOXDRAW_DOUBLE_DOWN_RIGHT          0x2554
#define BOXDRAW_DOWN_LEFT_DOUBLE           0x2555
#define BOXDRAW_DOWN_DOUBLE_LEFT           0x2556
#define BOXDRAW_DOUBLE_DOWN_LEFT           0x2557
#define BOXDRAW_UP_RIGHT_DOUBLE            0x2558
#define BOXDRAW_UP_DOUBLE_RIGHT            0x2559
#define BOXDRAW_DOUBLE_UP_RIGHT            0x255A
#define BOXDRAW_UP_LEFT_DOUBLE             0x255B
#define BOXDRAW_UP_DOUBLE_LEFT             0x255C
#define BOXDRAW_DOUBLE_UP_LEFT             0x255D
#define BOXDRAW_VERTICAL_RIGHT_DOUBLE      0x255E
#define BOXDRAW_VERTICAL_DOUBLE_RIGHT      0x255F
#define BOXDRAW_DOUBLE_VERTICAL_RIGHT      0x2560
#define BOXDRAW_VERTICAL_LEFT_DOUBLE       0x2561
#define BOXDRAW_VERTICAL_DOUBLE_LEFT       0x2562
#define BOXDRAW_DOUBLE_VERTICAL_LEFT       0x2563
#define BOXDRAW_DOWN_HORIZONTAL_DOUBLE     0x2564
#define BOXDRAW_DOWN_DOUBLE_HORIZONTAL     0x2565
#define BOXDRAW_DOUBLE_DOWN_HORIZONTAL     0x2566
#define BOXDRAW_UP_HORIZONTAL_DOUBLE       0x2567
#define BOXDRAW_UP_DOUBLE_HORIZONTAL       0x2568
#define BOXDRAW_DOUBLE_UP_HORIZONTAL       0x2569
#define BOXDRAW_VERTICAL_HORIZONTAL_DOUBLE 0x256A
#define BOXDRAW_VERTICAL_DOUBLE_HORIZONTAL 0x256B
#define BOXDRAW_DOUBLE_VERTICAL_HORIZONTAL 0x256C

#define BLOCKELEMENT_FULL_BLOCK  0x2588
#define BLOCKELEMENT_LIGHT_SHADE 0x2591

#define GEOMETRICSHAPE_UP_TRIANGLE    0x25B2
#define GEOMETRICSHAPE_RIGHT_TRIANGLE 0x25BA
#define GEOMETRICSHAPE_DOWN_TRIANGLE  0x25BC
#define GEOMETRICSHAPE_LEFT_TRIANGLE  0x25C4

#define ARROW_UP   0x2191
#define ARROW_DOWN 0x2193

#endif /* __PLATFORM_EFI_PROTOCOLS_SIMPLETEXT_H__ */
