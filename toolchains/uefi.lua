toolchain("uefi")
    set_kind("standalone")

    set_toolset("cc", "clang")
    set_toolset("cxx", "clang", "clang++")
    set_toolset("ld", "lld-link", "lld-link")
    set_toolset("sh", "clang++", "clang")
    set_toolset("ar", "ar")
    set_toolset("ex", "ar")
    set_toolset("strip", "strip")
    set_toolset("mm", "clang")
    set_toolset("mxx", "clang", "clang++")
    set_toolset("as", "clang")

    add_defines("UEFI")

    on_check(function (toolchain)
        local ret = import("lib.detect.find_tool")("lld-link")
        if ret then
            return import("lib.detect.find_tool")("clang")
        else
            return nil
        end
    end)

    on_load(function (toolchain)
        toolchain:add("cflags", "-nostdlib -nostdlibinc -mabi=ms -target x86_64-pc-win32-coff -fno-stack-protector -fno-stack-clash-protection -fno-strict-aliasing -fno-stack-check -fshort-wchar -mno-red-zone -Wno-incompatible-library-redeclaration -ffreestanding -Wno-builtin-requires-header -Wno-incompatible-library-redeclaration -mno-stack-arg-probe")
        toolchain:add("includedirs", "$(projectdir)/DarwinBoot/include", "$(projectdir)/External/POSIX-UEFI/uefi")

        toolchain:add("ldflags", "-subsystem:efi_application -nodefaultlib -dll -entry:EFIMain")
    end)