includes("../../configs/*.lua")

target("ARMwinBoot")
    set_basename("DarwinBoot.$(platform).$(board).bin")

    add_files(
        "$(projectdir)/DarwinBoot/ARM/Machine/Common/*_$(arch).s",
        "$(projectdir)/DarwinBoot/ARM/CorePlatform/Arch/$(arch)/*.s",
        "$(projectdir)/DarwinBoot/ARM/CorePlatform/Arch/$(arch)/*.c",
        "$(projectdir)/DarwinBoot/ARM/CorePlatform/Drivers/**.c",
        "$(projectdir)/DarwinBoot/ARM/Machine/" ..machinedir.. "/*.s",
        "$(projectdir)/DarwinBoot/ARM/Machine/" ..machinedir.. "/*.c",
        -- "$(projectdir)/DarwinBoot/CoreDarwinBoot/Platform/**.c",
        "$(projectdir)/DarwinBoot/CoreDarwinBoot/libc/**.c",
        "$(projectdir)/DarwinBoot/CoreDarwinBoot/*.c"
    )

    add_cflags(
        "-mcpu=" ..cpu,
        "-Wl,--script,$(projectdir)/DarwinBoot/ARM/Machine/" ..machinedir.. "/link.ld"
    )

    if is_arch("armv6", "armv6k") then
        add_defines("__ARM_ARCH__=6")
    elseif is_arch("armv7") then
        add_defines("__ARM_ARCH__=7")
    elseif is_arch("arm64") then
        add_defines("__ARM_ARCH__=8")
    end
