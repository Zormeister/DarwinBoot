if is_plat("bcm2837") then

    add_defines(
        "BCM2837",
        "DRIVER_BCM2835_UART",
        "DRIVER_BCM2835_DMA",
        "DRIVER_BCM2835_PWM"
    )

    local board = os.getenv("BOARD")

    add_defines("BOARD_BCM2837_" .. board)

    machinedir = "RPi"

    cpu = "cortex-a53"

    build_toolchain = "arm-elf"

elseif is_plat("bcm2837-emulated") then

    add_defines(
        "BCM2837",
        "DRIVER_BCM2835_UART",
        "DRIVER_BCM2835_DMA"
    )

    local board = os.getenv("BOARD")

    add_defines("BOARD_BCM2837_" .. board)

    machinedir = "RPi"

    cpu = "cortex-a53"

    build_toolchain = "arm-elf"
end