if is_plat("vmqemu") then

    add_defines(
        "VMQEMU",
        "DRIVER_PL011_UART"
    )

    add_defines("BOARD_VMQEMU_VMQEMU")
end