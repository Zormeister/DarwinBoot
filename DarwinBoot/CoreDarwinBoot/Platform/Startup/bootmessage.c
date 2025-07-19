// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/libc_compat.h>
#include <CorePlatform/Foundation.h>

/* TODO: reloc? */
const char BootMessage[] = {
    "=======================================\n"
    "::\n"
    /*  <Payload> <Board Config> */
    ":: %s for %s, Copyright (C) 2024-2025 Zormeister\n"
    "::\n"
    ":: BUILD_TAG: %s\n"
    "::\n"
    ":: BUILD_STYLE: %s\n"
    "::\n"
    ":: COMPILER: %s (%s)\n"
    "::\n"
    ":: CPID: %04x BORD: %02x \n"
    "::\n"
    "=======================================\n"
};

#if defined(DARWINBOOTEFI)
#define BOARD_CONFIG TARGET_ARCH

#if defined(EFIJUMPSTART)
#define PAYLOAD_CONFIG "DarwinBoot EFI JumpStart"
#elif defined(EFIDISKBOOT)
#define PAYLOAD_CONFIG "DarwinBoot EFI Loader"
#else
#error Unknown Configuration for UEFI
#endif

#elif defined(DARWINBOOTARM)

#if defined(ARMSTAGE1)
#define PAYLOAD_CONFIG "DarwinBoot Stage1"
#else
#error Unknown Configuration for ARM
#endif
#else
#error Unknown Configuration
#endif

#ifndef BUILD_TAG
#define BUILD_TAG "localbuild"
#endif

/* Will Darwin support i386 again, like, ever? */
/* If so I think I should map the following: */
/*
 * x86_64 PCs:
 * Target: x64PC
 * TargetType: x64pc
 * Platform: x64PC
 * KernelPlatform: <blank>
 * SDKPlatform: MacOSX
 * ChipID: 0x8664
 * BoardID: 0xFF
 *
 * i386 PCs:
 * Target: i386PC64
 * TargetType: i386pc
 * Platform: i386
 * KernelPlatform: <blank>
 * SDKPlatform: MacOSX
 * ChipID: 0x1386
 * BoardID: 0xFF
 *
 *
 * Apple's x86legacyap target uses 0x8012 + BORD value of 0xF0 IIRC.
 * IDGAF about conforming to their IMG4 standards though.
 * i can configure and sign my IMG4s myself tyvm.
 * i just need to embed the right CAs smh
 */
void BootupMessageSend(void)
{
    printf(BootMessage, PAYLOAD_CONFIG, BOARD_CONFIG, BUILD_TAG, CURRENT_CONFIG,
#if defined(DARWINBOOTARM)
        /* TODO:  */
        CPGetDeviceIdentity()->ChipID,
        CPGetDeviceIdentity()->BoardID,
#elif defined(DARWINBOOTEFI)
        BUILD_TOOL,
        COMPILER_VERSION,
        0x8664, /* TODO: literally establish x86 constants for IMG4. */
        0xFF
#endif
    );
}
