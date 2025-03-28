target("UEFI JumpStart")
    set_basename("BOOT$(arch).efi")
    add_includedirs("$(projectdir)/DarwinBoot/include")
    set_languages("c17")
    set_kind("binary")

    add_files(
        "$(projectdir)/DarwinBoot/CoreDarwinBoot/Platform/**.c",
        "$(projectdir)/DarwinBoot/CoreDarwinBoot/libc/*.c",
        "$(projectdir)/DarwinBoot/CoreDarwinBoot/*.c",
        "$(projectdir)/DarwinBoot/UEFI/JumpStart/*.c",

        "$(projectdir)/External/POSIX-UEFI/uefi/stat.c",
        "$(projectdir)/External/POSIX-UEFI/uefi/stdlib.c",
        "$(projectdir)/External/POSIX-UEFI/uefi/stdio.c",
        "$(projectdir)/External/POSIX-UEFI/uefi/string.c",
        "$(projectdir)/External/POSIX-UEFI/uefi/time.c",
        "$(projectdir)/External/POSIX-UEFI/uefi/unistd.c"
    )

    if is_arch("x64", "x86") then
        remove_files("$(projectdir)/DarwinBoot/CoreDarwinBoot/Platform/ARM/*.c")
    elseif is_arch("arm64", "armv7") then
        remove_files("$(projectdir)/DarwinBoot/CoreDarwinBoot/Platform/x86/*.c")
    end

    if is_mode("debug") then
        add_defines("CONFIG_DEBUG=1", "LIBC_PANIC_ON_NULLPTR")
    end

    on_install(function (target)
        os.cp(target:targetfile(), path.join(target:installdir(), "EFI/BOOT/", target:basename()))
    end)