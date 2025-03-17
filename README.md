# DarwinBoot

## THANK YOUS:

I would love to say a huge thank you to:
- The maintainers of OpenCorePkg (vit, DownloadFritz, Goldfish, etc)
- The maintainers of the OSDev wiki
- worproject for their Pi 5 UEFI work
- InSaneDarwin and the rest of the PureDarwin contributors
- bzxt for POSIX-UEFI

## What is DarwinBoot?
DarwinBoot is, as the name implies, a bootloader for Darwin/the XNU kernel.

FYI:
- This is a hobbyist project
- It isn't feature-complete: eg, APFS, FileVault, and all of those fancy macOS features

It can:
- Do a trick

Contributions to this project are welcome with open arms!

## How To Build

DarwinBoot uses XMake to build.

UEFI targets are fairly simple, however the following packages are required:
- Arch: `clang`, `lld`

Then, run `xmake f -p uefi -a x64`, then run `xmake`
It should then build DarwinBoot's UEFI components and files.

### ARM Targets:

The ARM port of DarwinBoot currently is focused on two targets:
- BCM2712 (Raspberry Pi 5 to be specific, BCM2712D0 has not been accounted for yet)
- VMQEMU (The generic QEMU virtual platform)

## Valid XMake targets

### BCM2712

Boards:
- PI5 | Raspberry Pi 5

### BCM2711

Boards:
- PI4 | Raspberry Pi 4
- PI4B | Raspberry Pi 4 Model B

