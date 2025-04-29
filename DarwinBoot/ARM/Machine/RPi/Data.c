// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <CorePlatform/Foundation.h>

UInt32 GetCPIDFromBoardRev(UInt32 rev) {
    UInt32 cpu = (rev >> 12) & 0x7; /* 3-bit field. */
    switch (cpu) {
        case 0x0:
            return 0x2708; /* BCM2835 - BCM2708 is the CPU die prior to the DRAM being packaged on, apparently? */
        case 0x1:
            return 0x2709; /* BCM2836 - BCM2709 is the CPU die prior to the DRAM being packaged on, apparently? */
        case 0x2:
            return 0x2710; /* BCM2837 - BCM2710 is the CPU die prior to the DRAM being packaged on, apparently? */
        case 0x3:
            return 0x2711;
        case 0x4:
            return 0x2712;
    }

    return 0x0000; /* i hope this is invalid */
}

/* honestly we could convert the model identifier from the field provided by the devicetree */
const char *GetTargetTypeFromBoardRevision(uint32_t revision) {
    uint32_t hwrev = revision & 0x7;
    uint32_t product = (revision >> 4) & 0xFF;
    switch (product) {
        case 0x00:
            return "rpia";
        case 0x01:
            return "rpib";
        case 0x02:
            return "rpiax";
        case 0x03:
            return "rpibx";
        case 0x04:
            if (hwrev == 2) {
                return "rpi2br2";
            } else {
                return "rpi2b";
            }
        case 0x06:
            return "cmpi1";
        case 0x08:
            return "rpi3b";
        case 0x09:
            return "rpizero";
        case 0x0A:
            return "cmpi3";
        case 0x0C:
            return "rpizerow";
        case 0x0D:
            return "rpi3bx";
        case 0x0E:
            return "rpi3ax";
        case 0x10:
            return "cmpi3x";
        case 0x11:
            return "rpi4";
        case 0x12:
            return "rpizero2w";
        case 0x13:
            return "kbpi4";
    }
    return NULL;
}
