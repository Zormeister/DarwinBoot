if is_plat("vmqemu") then

    add_defines(
        "VMQEMU",
        "DRIVER_PL011_UART"
    )

    add_defines("BOARD_VMQEMU_VMQEMU")

    build_toolchain = "arm-eabi"

    if is_arch("armv6") then
        cpu = "arm1136j-s"
    elseif is_arch("armv7") then
        cpu = "cortex-a53"
    elseif is_arch("arm64") then
        cpu = "cortex-a72"
    end
end