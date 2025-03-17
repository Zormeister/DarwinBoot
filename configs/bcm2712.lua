if is_plat("bcm2712") then

    add_defines(
        "BCM2712",
        "DRIVER_BCMPCIE",
        "DRIVER_BCM_GIGABIT_ETHERNET",
        "DRIVER_BCM2835_UART",
        "DRIVER_BCM2835_DMA",
        "DRIVER_BCM2835_PWM"
    )

    local board = os.getenv("BOARD")

    add_defines("BOARD_BCM2712_$(board)")

    machine = board

elseif is_plat("bcm2712-emulated") then

    add_defines(
        "BCM2712",
        "DRIVER_BCM2835_UART",
        "DRIVER_BCM2835_DMA"
    )

    local board = os.getenv("BOARD")

    add_defines("BOARD_BCM2712_$(board)")

    machine = board

    print(machine)

end