# Building DarwinBoot

## xmake

DarwinBoot uses a build system called xmake to compile, it was chosen for its flexibility with creating custom toolchains and extensible nature

Downloading xmake is easy and painless.

### Linux/macOS

xmake can be installed by running either of these two commands:

```
curl -fsSL https://xmake.io/shget.text | bash
```

OR

```
wget https://xmake.io/shget.text -O - | bash
```

### Windows

xmake on Windows can be annoying, I had to fight with it trying to find the MSVC linker and compiler.

Again, xmake is installable by invoking a PowerShell command:

```
Invoke-Expression (Invoke-Webrequest 'https://xmake.io/psget.text' -UseBasicParsing).Content
```


## Toolchain

DarwinBoot uses the LLVM compiler to cross-compile for UEFI and the ARM binary formats.

A **complete** LLVM toolchain is required.

### macOS

Apple's own compiler should work fine here, at most you'll need to run Homebrew and download the LLVM linker, lld.

Once lld (and Homebrew's LLVM if you prefer) is installed, you are ready to build DarwinBoot.

### Linux

Usually Linux systems use GCC, so there is a high chance you'll need to download the packages for clang and lld.

#### Arch Linux

Arch Linux is relatively easy to do this on.

```
sudo pacman -S clang lld
```

Once these are installed, you are ready to build DarwinBoot.

### Windows

This is where it gets annoying, xmake will either refuse to work because it can't locate `cl.exe` and `link.exe` or it'll work like magic.

The solution to this is to add the MSVC tools to your PATH variables, alongside the LLVM tools.

You can download LLVM from the [llvm-project](https://github.com/llvm/llvm-project/releases) GitHub repository, using the `win64.exe` installer for x86_64 hosts or `woa64.exe` installer for Windows On ARM hosts.

Once both LLVM and MSVC are added to the PATH, you are now ready to build DarwinBoot.

## Building

DarwinBoot has different configurations depending on the 'platform' it will be ran on.

For a comprehensive list of available targets, see [TARGETS.md](TARGETS.md)

The xmake scripts use the 'platform' variable to adjust for the hardware and environment, see the files in the configs folder for reference.

### UEFI

To build for UEFI, it's as easy as running the following commands:

```
xmake f -p uefi -a <UEFI Architecture>

xmake

xmake install -o <DSTROOT>
```

Where 'UEFI Architecture' refers to the architecture that is used for the `BOOT.efi` name and DSTROOT is the root of where the binaries should be installed.

Valid UEFI architectures that DarwinBoot will compile for are:
- `x64` (x86_64)

DarwinBoot's lua scripts will accept the architectures of:
- `IA32` (i386)
- `AArch64` (ARM64)

However, these architectures aren't inherently supported, building and using them is at your own risk.

### DarwinBoot ARM/ARM64/Standalone

DarwinBoot ARM, also known as 'ARMwinBoot' in various pieces of the source code, is just as easily compiled as the UEFI version of DarwinBoot

To do so, you'll want to know which platform you're compiling for.

This is as easy as:
- Selecting a target from [TARGETS.md](TARGETS.md)
- Inuptting the name in all lowercase letters

Run the following commands to build the standalone version of DarwinBoot:

```
xmake f -p <Platform Target> -a <Architecture>

xmake

xmake install -o <DSTROOT>
```

Where Platform Target is the specific target such as `bcm2712` or `integratorcp`, Architecture is the specific architeture to compile for and DSTROOT is the root of where the binaries should be installed.

Valid architecture for DarwinBoot ARM are:
- `arm64` (64-bit ARMv8.x and ARMv9.x)
- `armv7` (32-bit ARMv7)
- `armv6k` (32-bit ARMv6k)
- `armv6` (32-bit ARMv6)

## Installing

Installing DarwinBoot is easy, however certain boards may need different conditions.

For example:
- Raspberry Pi boards use a specific `kernel.img` to boot.

I need to handle these cases in the future.

The command to install DarwinBoot was described in the building section, however for completeness I'll provide it here.

```
xmake install -o <DSTROOT>
```

Where DSTROOT is the root of the folder that the binaries should be installed in.
