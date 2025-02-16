set(BCM2712 "YES")
set(CPU_TUNE "cortex-a76")

set(DRIVER_BCM2835_AUX_UART "YES")
set(DRIVER_ARM_PL011 "YES")

set(TOOLCHAIN_BUILD_ELF YES)

# QEMU doesn't emulate the PCIe bridge or PWM devices.
# Is there a way I can fetch the current boot device from the Pi?
if(NOT DEFINED EMULATED OR NOT EMULATED STREQUAL "YES")
set(DRIVER_BCM_PCIE "YES")
set(DRIVER_BCM_GETHNET "YES")
set(DRIVER_BCM2835_PWM "YES")
endif()

if(BOARD STREQUAL "Pi5")
string(APPEND CMAKE_C_FLAGS "-DBOARD_BCM2712_PI5")
set(DID_SET_BOARD "YES")
set(MACHINE "RPi")
endif()

if(NOT DEFINED DID_SET_BOARD)
message(FATAL_ERROR "Unsupported Board config.")
endif()
