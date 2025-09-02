// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

enum _ARM_MIDR_IMPLEMENTER {
    Reserved = 0,
    ARM = 0x41,
    Broadcom = 0x42,
    Cavium = 0x43,
    DEC = 0x44,
    Fujitsu = 0x46,
    Infineon = 0x49,
    Motorola = 0x4D,
    NVIDIA = 0x4E,
    AMC = 0x50,
    Qualcomm = 0x51,
    Marvell = 0x56,
    Apple = 0x61, /* This isn't listed by the ARM docs. */
    Intel = 0x69,
    Ampere = 0xC0,
} typedef ARM_MIDR_IMPLEMENTER;

enum _ARM_LTD_PART_NUMBERS {
    ARM810 = 0x810,
    ARM920 = 0x920,
    CortexA72 = 0xD08,
    CortexA76 = 0xD0B,
} typedef ARM_LTD_PART_NUMBERS;

/* how 2 get arch from other regs??? */
enum _ARM_MIDR_ARCHITECTURE {
    ARMv4 = 1,
    ARMv4T = 2,
    ARMv5 = 3,
    ARMv5T = 4,
    ARMv5TE = 5,
    ARMv5TEJ = 6,
    ARMv6 = 7,
    USE_OTHER_IDR = 15,
} typedef ARM_MIDR_ARCHITECTURE;

enum _APPLE_PART_NUMBER {
    Typhoon = 0x2,             /* H7 - T7000 - Fiji */
    TyphoonCapri = 0x3,        /* H7G - A8X allegedly */
    Twister = 0x4,             /* H8 - S8000 (A9) - Maui */
    TwisterElbaMalta = 0x5,    /* H8G, H8O - S8001 (A9X) and S8003 (TSMC A9), Elba and Malta respectively */
    Hurricane = 0x6,           /* H9 - T8010 (A10) and T8012 (T2) - Cayman and Gibraltar respectively */
    HurricaneMyst = 0x7,       /* H9G - T8011 (A10X) - Myst */
    Monsoon = 0x8,             /* H10 - T8015 (A11) - Skye Perf */
    Mistral = 0x9,             /* H10 - T8015 (A11) - Skye Eff */
    Vortex = 0xB,              /* H11 - T8020 (A12) - Cyprus Perf */
    Tempest = 0xC,             /* H11 - T8020 (A12) - Cyprus Eff */
    TempestM9 = 0xF,           /* M9 - T8006 (S4 and S5) Eff */
    VortexAruba = 0x10,        /* H11G - T8027 (A12X and A12Z?) - Aruba Perf */
    TempestAruba = 0x11,       /* H11G - T8027 (A12X and A12Z?) - Aruba Eff */
    Lightning = 0x12,          /* H12 - T8030 (A13) - Cebu Perf */
    Thunder = 0x13,            /* H12 - T8030 (A13) - Cebu Eff */
    ThunderM10 = 0x26,         /* M10 - T8301 (S6, S7 and S8) Eff */
    Icestorm = 0x20,           /* H13 - T8101 (A14) - Cicily Perf */
    Firestorm = 0x21,          /* H13 - T8101 (A14) - Cicily Eff */
    IcestormTonga = 0x22,      /* H13G - T8103 (M1) - Tonga Perf */
    FirestormTonga = 0x23,     /* H13G - T8103 (M1) - Tonga Eff */
    IcestormJadeChop = 0x24,   /* T6000 (M1 Pro) - Jade Chop Eff */
    IcestormJadeDie = 0x28,    /* T6001 (M1 Max) and T6002 (M1 Ultra) - Jade Die Eff */
    FirestormJadeChop = 0x25,  /* T6000 (M1 Pro) - Jade Chop Eff */
    FirestormJadeDie = 0x29,   /* T6001 and T6002 */
    Blizzard = 0x30,           /* H14 - T8110 (A15) - Ellis Perf */
    Avalanche = 0x31,          /* H14 - T8110 (A15) - Ellis Eff */
    BlizzardStaten = 0x32,     /* H14G - T8112 (M2) - Staten Perf */
    AvalanceStaten = 0x33,     /* H14G - T8112 (M2) - Staten Eff */
    BlizzardRhodesChop = 0x34, /* H14C - T6020 (M2 Pro) - Rhodes Chop Perf */
    AvalanceRhodesChop = 0x35, /* H14C - T6020 (M2 Pro) - Rhodes Chop Eff */
    BlizzardRhodesDie = 0x38,  /* H14D and H14M (? guessed name) - T6021 (M2 Max) and T6022 (M2 Ultra) - Rhodes Die Perf */
    AvalanceRhodesDie = 0x39,  /* H14D and H14M (? guessed name) - T6021 (M2 Max) and T6022 (M2 Ultra) - Rhodes Die Eff */
    Sawtooth = 0x40,           /* H15 - T8120 (A16) - Crete Eff */
    Everest = 0x41,            /* H15 - T8120 (A16) - Crete Perf */
    EverestIbiza = 0x42,       /* H15G - T8122 (M3) - Ibiza Perf */
    SawtoothIbiza = 0x43,      /* H15G - T8122 (M3) - Ibiza Eff */
    EverestPalma = 0x48,       /* H15C, H15D and H15M - T6031 (M3 Max), T6032 (M3 Ultra) and T6034 (M3 Max) - Palma Perf */
    SawtoothPalma = 0x49,      /* H15C, H15D and H15M - T6031 (M3 Max), T6032 (M3 Ultra) and T6034 (M3 Max) - Palma Eff */
    EverestColl = 0x50,        /* H16P - T8130 (A16) - Coll Perf */
    SawtoothColl = 0x51,       /* H16P - T8130 (A16) - Coll Eff */
    EverestLobos = 0x44,       /* H15S - T6030 (M3 Pro) - Lobos Perf */
    SawtoothLobos = 0x45,      /* H15S - T6030 (M3 Pro) - Lobos Eff */
    SawtoothM11 = 0x46,        /* M11 - T8310 (M3) - Caicos Eff */
    EverestDonan = 0x52,       /* H16G - T8132 (M4) - Donan Perf */
    SawtoothDonan = 0x53,      /* H16G - T8132 (M4) - Donan Perf */
    EverestBravaS = 0x54,      /* H16S - T6040 (M4 Pro) - Brava S Eff */
    SawtoothBravaS = 0x55,     /* H16S - T6040 (M4 Pro) - Brava S Perf */
    EverestBravaC = 0x58,      /* H16C - T6041 (M4 Max) - Brava C Eff */
    SawtoothBravaC = 0x59,     /* H16C - T6041 (M4 Max) - Brava C Perf */
} typedef APPLE_CPU_PART_NUMBER;
