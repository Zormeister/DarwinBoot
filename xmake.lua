includes("toolchains/*.lua")

add_rules("mode.release", "mode.debug")

if is_plat("uefi") then

set_allowedarchs("x64", "x86", "AArch64")

set_toolchains("uefi")

includes("targets/UEFI/*.lua")

elseif is_arch("arm64", "armv7") then

includes("configs/*.lua")
includes("targets/ARM/*.lua")

end