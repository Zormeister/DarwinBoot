# DarwinBoot

## What is DarwinBoot?
DarwinBoot is, as the name implies, a bootloader for Darwin/the XNU kernel.

FYI:
- This is a hobbyist project
- It isn't feature-complete: eg, APFS, FileVault, and all of those fancy macOS features

It can:
- Do a trick

Contributions to this project are welcome with open arms!

# HOW TO BUILD

DarwinBoot **does not** yet build, but here are some WIP instructions for when that time comes:

## Linux

This can be built using GCC or LLVM/Clang, pick your preference, they both build.

### GCC
You'll want to grab the MinGW64 GCC toolchain, that's:
- `mingw-w64-gcc` for Arch Linux.
- `gcc-mingw-w64` for Ubuntu and Debian.

Run CMake, build as usual.

### LLVM

LLVM needs more than one package.

You'll want to grab the following:
- `llvm`, `clang` and `lld` on Arch Linux & Ubuntu + Debian.

## macOS

compilation is a no-go for now
