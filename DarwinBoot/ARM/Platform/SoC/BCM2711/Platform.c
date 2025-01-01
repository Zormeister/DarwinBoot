
#include <CorePlatform/Driver.h>
#include <CorePlatform/Foundation.h>
#include <Platform/SoC/BCM2711/MemoryMap.h>
#include <Platform/SoC/BCM2711/Peripherals.h>
#include <Platform/SoC/BCM2711/Regs/AuxRegs.h>
#include <Platform/SoC/BCM2711/Regs/UART1Regs.h>
#include <Platform/SoC/BCM2711/Regs/GPIORegs.h>

/* where should I even put this so that CorePl- actually I can just make a function on startup */
PlatformDeviceDescriptor platform_devices[] = {
    {"aux,bcm2835", {AUX_BASE}, {0x100}},
    /* Consider UART1 base size 0x40 since the regs only go up to that extent. */
    {"aux-uart,bcm2835", {UART1_BASE}, {0x40}},
    {"uart,arm-pl011", {UART0_BASE}, {0x200}}, /* I didn't research the reg size. I'll fix this later. */
    {NULL, NULL, NULL},
};