add_rules("mode.release", "mode.debug")

add_sysincludedirs("$(projectdir)", "$(projectdir)/External/corecrypto/include")

if is_plat("uefi") then

    includes("toolchains/uefi.lua")

    set_allowedarchs("x64", "x86", "AArch64")

    set_toolchains("uefi")

    includes("External/libs.lua")
    includes("targets/UEFI/*.lua")

elseif is_arch("arm64", "armv7", "armv6", "armv6k") then

    print("=== DarwinBoot ARM ===")

    includes("toolchains/arm-eabi.lua")
    includes("toolchains/arm-elf.lua")

    includes("configs/*.lua")

    set_toolchains(build_toolchain)

    includes("External/libs.lua")
    includes("targets/ARM/*.lua")

    -- this variable is set by the configs. i wanna see if it persists
    print(build_toolchain)

end