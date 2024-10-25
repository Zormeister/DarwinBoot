cmake_minimum_required(VERSION 3.10)
project(DarwinBoot C)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_executable(JumpStart.efi)

target_include_directories(JumpStart.efi PRIVATE CoreDarwinBoot/include)
target_sources(JumpStart.efi PRIVATE
    CoreDarwinBoot/Sources/CPUInfo.c
    CoreDarwinBoot/Sources/Globals.c
    DarwinBoot/JumpStart/main.c
)
