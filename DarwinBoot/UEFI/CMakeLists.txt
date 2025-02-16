
string(APPEND CMAKE_C_FLAGS "-mabi=msabi")

add_executable (
    JumpStart.efi
    WIN32

    JumpStart/main.c
)