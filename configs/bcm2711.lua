if is_plat("bcm2711") then

    add_defines(
        "BCM2711",
        "DRIVER_BCMPCIE",
        "DRIVER_BCM_GIGABIT_ETHERNET",
        "DRIVER_BCM2835_UART",
        "DRIVER_BCM2835_DMA",
        "DRIVER_BCM2835_PWM"
    )

    local board = os.getenv("BOARD")

    add_defines("BOARD_BCM2711_" .. board)

    machinedir = "RPi"

    cpu = "cortex-a72"

    build_toolchain = "arm-elf"

elseif is_plat("bcm2711-emulated") then

    add_defines(
        "BCM2711",
        "DRIVER_BCM2835_UART",
        "DRIVER_BCM2835_DMA"
    )

    local board = os.getenv("BOARD")

    add_defines("BOARD_BCM2711_" .. board)

    machinedir = "RPi"

    cpu = "cortex-a72"

    build_toolchain = "arm-elf"
end