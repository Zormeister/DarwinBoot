# DarwinBoot

## THANK YOUS:

I would love to say a huge thank you to:
- The maintainers of OpenCorePkg (vit, DownloadFritz, Goldfish, etc)
- The maintainers of the OSDev wiki
- worproject's Pi 5 UEFI work
- InSaneDarwin and the rest of the PureDarwin contributors

## What is DarwinBoot?
DarwinBoot is, as the name implies, a bootloader for Darwin/the XNU kernel.

FYI:
- This is a hobbyist project
- It isn't feature-complete: eg, APFS, FileVault, and all of those fancy macOS features

It can:
- Do a trick

Contributions to this project are welcome with open arms!

## ARM Targets:

The ARM port of DarwinBoot currently is focused on two targets:
- BCM2712 (Raspberry Pi 5 to be specific, BCM2712D0 has not been accounted for yet)
- VMQEMU (The generic QEMU virtual platform)