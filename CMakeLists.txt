cmake_minimum_required(VERSION 3.10)
project(DarwinBoot C ASM)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

execute_process(COMMAND whoami OUTPUT_VARIABLE BUILDER)
string(STRIP ${BUILDER} BUILDER)

execute_process(COMMAND date OUTPUT_VARIABLE BUILD_DATE)

if(NOT DEFINED BUILD_VARIANT)

set(BUILD_VARIANT "RELEASE")

endif()

if(NOT DEFINED ARCH)
set(ARCH "x86_64")
endif()

if(ARCH STREQUAL "ARM64")

set(DARWINBOOT_ARM YES)

if(NOT DEFINED BOARD OR SOC)
message(FATAL_ERROR "No Board or SoC config.")
endif()

include(cmake/Configs/${SOC}.cmake)

add_subdirectory(DarwinBoot/ARM)

endif()

if(ARCH STREQUAL "x86_64")

add_subdirectory(DarwinBoot/UEFI)

endif()
