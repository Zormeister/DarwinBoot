includes("../../toolchains/uefi-dxe.lua")

target("CoreCrypto UEFI DXE driver")
    set_toolchains("uefi-dxe")
    set_basename("CoreCryptoDxe.efi")
    add_includedirs("$(projectdir)/DarwinBoot/include")
    set_languages("c17")
    set_kind("binary")

    add_defines("EFIDISKBOOT", "DARWINBOOTEFI")

    add_files(
        "$(projectdir)/DarwinBoot/CoreDarwinBoot/Platform/**.c",
        "$(projectdir)/DarwinBoot/CoreDarwinBoot/libc/**.c",
        "$(projectdir)/DarwinBoot/CoreDarwinBoot/*.c",
        "$(projectdir)/DarwinBoot/UEFI/Platform/**.c",
        "$(projectdir)/DarwinBoot/UEFI/CoreCryptoDxe/*.c"
    )
    
    add_deps("libprintf")
    add_deps("libcorecrypto_darwinboot")

    if is_arch("x64", "x86") then
        remove_files("$(projectdir)/DarwinBoot/CoreDarwinBoot/Platform/ARM/*.c")
    elseif is_arch("arm64", "armv7") then
        remove_files("$(projectdir)/DarwinBoot/CoreDarwinBoot/Platform/x86/*.c")
    end

    if is_mode("debug") then
        add_defines("CONFIG_DEBUG=1", "LIBC_PANIC_ON_NULLPTR")
    end

    on_install(function (target)
        os.cp(target:targetfile(), path.join(target:installdir(), "DarwinBoot/Drivers/", target:basename()))
    end)
