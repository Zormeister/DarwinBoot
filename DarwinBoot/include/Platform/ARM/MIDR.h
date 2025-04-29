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
    Typhoon = 0x2, /* H7 */
    TyphoonCapri = 0x3, /* H7G - A8X allegedly */
    Twister = 0x4, /* H8 */
    TwisterElbaMalta = 0x5, /* H8G, H8M - A9X and the TSMC A9s */
    Hurricane = 0x6, /* H9 */
    HurricaneMyst = 0x7, /* H9G - A10X allegedly */
    Monsoon = 0x8, /* H10 Perf */
    Mistral = 0x9, /* H10 Eff */
    Vortex = 0xB, /* H11 Perf */
    Tempest = 0xC, /* H11 Eff */
    TempestM9 = 0xF, /* M9 Eff */
    VortexAruba = 0x10, /* H11G Perf */
    TempestAruba = 0x11, /* H11G Eff */
    Lightning = 0x12, /* H12 Perf */
    Thunder = 0x13, /* H12 Eff */
    ThunderM10 = 0x26, /* M10 Eff */
    Icestorm = 0x20, /* t8101 Perf */
    Firestorm = 0x21, /* t8101 eff */
    IcestormTonga = 0x22, /* t8103 perf */
    FirestormTonga = 0x23, /* t8103 eff */
    IcestormJadeChop = 0x24, /* t6000 */
    IcestormJadeDie = 0x28, /* t6001/t6002 */
    FirestormJadeChop = 0x25, /* t6000 */
    FirestormJadeDie = 0x29, /* t6001/t6002 */
    Blizzard = 0x30, /* A14 Perf */
    Avalanche = 0x31, /* A14 Eff */
    BlizzardStaten = 0x32, /* M2 Blizzard Core */
    AvalanceStaten = 0x33, /* M2 Avalanche Core */
    BlizzardRhodesChop = 0x34, /* M2 Pro Blizzard Core */
    AvalanceRhodesChop = 0x35, /* M2 Pro Avalanche Core */
    BlizzardRhodesDie = 0x38, /* M2 Max/Ultra Blizzard Core */
    AvalanceRhodesDie = 0x39, /* M2 Max/Ultra Avalanche Core */
    Sawtooth = 0x40, /* A15 Perf */
    Everest = 0x41, /* A15 Eff */
    SawtoothIbiza = 0x42, /* M3 Sawtooth */
} typedef APPLE_CPU_PART_NUMBER;
