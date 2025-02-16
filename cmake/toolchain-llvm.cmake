# LLVM Toolchain for DarwinBoot compiling.

# We ASSUME that we have variables from the root file.

if(DARWINBOOT_ARM EQUAL YES)

set(CMAKE_SYSTEM_PROCESSOR arm64)

set(CMAKE_C_COMPILER clang)

if(TOOLCHAIN_RESULT STREQUAL "EABI")
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER_TARGET arm64-none-eabi)
elseif(TOOLCHAIN_RESULT STREQUAL "ELF")
set(CMAKE_SYSTEM_NAME Generic-ELF)
set(CMAKE_C_COMPILER_TARGET arm64-none-elf)
endif()

endif()

if(DARWINBOOT_UEFI EQUAL YES)

set(CMAKE_SYSTEM_NAME Windows)
# TODO: other archs
set(CMAKE_C_COMPILER_TARGET x86_64-pc-windows-msvc)

endif()
