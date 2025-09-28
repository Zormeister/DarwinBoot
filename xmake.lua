add_rules("mode.release", "mode.debug")

add_sysincludedirs("$(projectdir)", "$(projectdir)/External/corecrypto/include")

if is_plat("uefi") then

    includes("toolchains/uefi.lua")

    set_allowedarchs("x64", "x86", "AArch64")

    set_toolchains("uefi")

    includes("External/libs.lua")
    includes("targets/UEFI/*.lua")

end