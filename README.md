# DarwinBoot

## THANK YOUS:

I would love to say a huge thank you to:
- The maintainers of OpenCorePkg (vit, DownloadFritz, Goldfish, etc)
- The maintainers of the OSDev wiki
- worproject for their Pi 5 UEFI work
- InSaneDarwin and the rest of the PureDarwin contributors
- bzxt for POSIX-UEFI
- Marco Paland for printf library used (see External/printf)

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

The following packages are required:
- Arch: `clang`, `lld`

Then, run `xmake f -p uefi -a x64`, then run `xmake`
It should then build DarwinBoot's UEFI components and files.
