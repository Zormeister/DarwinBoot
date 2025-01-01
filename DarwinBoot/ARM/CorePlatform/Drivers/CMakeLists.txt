
if (DRIVER_ARM_PL011 STREQUAL "YES")
target_sources(Serial/arm-pl011.c)
endif()

if (DRIVER_BCM2835_AUX_UART STREQUAL "YES")
target_sources(Serial/bcm2835-aux-uart.c)
endif()