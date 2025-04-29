if is_plat("integratorcp") then

    add_defines(
        "ARMINTEGRATORCP",
        "DRIVER_PRIMECELL_PL011"
    )

    add_defines("BOARD_ARM_INTEGRATORCP")

    machinedir = "ARM/IntegratorCP"

    build_toolchain = "arm-elf"

    cpu = "arm1136j-s"

    print("Config:")
    print("  Board: ARM Integrator CP")
    print("  Toolchain: arm-elf")
end