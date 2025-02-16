#! /bin/bash

# We need to modify the local Xcode Toolchain so we can build mtoc

# Apple Clang is no longer open-source, so we have to rely on headers from other sources.
LLVM_LTO_URL="https://raw.githubusercontent.com/swiftlang/llvm-project/refs/heads/stable/20240625/llvm/include/llvm-c/lto.h"
LLVM_EXTERNC_URL="https://raw.githubusercontent.com/swiftlang/llvm-project/refs/heads/stable/20240625/llvm/include/llvm-c/ExternC.h"

RUNNINGDIR=$PWD

XCTOOLCHAIN_CLANG_PATH="$(xcrun -f clang)"
XCTOOLCHAIN_PATH="${XCTOOLCHAIN_CLANG_PATH%/*/*/*}/"

echo "[DarwinBoot][TCInit]: Toolchain Init has started!"
echo "[DarwinBoot][TCInit]: Default Toolchain path: $XCTOOLCHAIN_PATH"

if [ ! -d $XCTOOLCHAIN_PATH/usr/local ]; then
  echo "[DarwinBoot][TCInit]: Commencing Toolchain init..."
  mkdir $PWD/tctmp
  curl -L -o "$PWD/tctmp/lto.h" "$LLVM_LTO_URL"
  curl -L -o "$PWD/tctmp/ExternC.h" "$LLVM_EXTERNC_URL"
  # macOS doesn't like us tampering with apps as a non-root user, 
  mkdir -p $XCTOOLCHAIN_PATH/usr/local/include/llvm-c
  cp $PWD/tctmp/* $XCTOOLCHAIN_PATH/usr/local/include/llvm-c/
  echo "[DarwinBoot][TCInit]: Copied lto.h & ExternC.h to Toolchain, as per cctools requires."
  rm -rf $PWD/tctmp
fi

if [ ! -d $PWD/External/cctools/build ]; then 
  cd $PWD/External/cctools
  patch -Np1 -i ../cctools-noriscv32.patch
  xcodebuild -target mtoc
  # We'll use this later to convert the Mach-O to a PE/COFF executable
fi
