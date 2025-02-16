set(BCM2711 YES)
set(CPU_TUNE "cortex-a72")

set(DRIVER_BCM2835_AUX_UART "YES")
set(DRIVER_ARM_PL011 "YES")

# QEMU doesn't emulate the PCIe bridge or PWM devices.
if(NOT DEFINED EMULATED OR NOT EMULATED STREQUAL "YES")
set(DRIVER_BCM_PCIE "YES")
set(DRIVER_BCM_GETHNET "YES")
set(DRIVER_BCM2835_PWM "YES")
endif()

if(BOARD STREQUAL "Pi4")
string(APPEND CMAKE_C_FLAGS "-DBOARD_BCM2711_PI4")
set(DID_SET_BOARD "YES")
set(MACHINE "RPi")
endif()

if(BOARD STREQUAL "Pi4B")
string(APPEND CMAKE_C_FLAGS "-DBOARD_BCM2711_PI4B")
set(DID_SET_BOARD "YES")
set(MACHINE "RPi")
endif()

if(NOT DEFINED DID_SET_BOARD)
message(FATAL_ERROR "Unsupported Board config.")
endif()