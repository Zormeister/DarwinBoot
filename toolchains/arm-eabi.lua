toolchain("arm-eabi")
    set_kind("standalone")

    set_toolset("cc", "clang")
    set_toolset("cxx", "clang", "clang++")
    set_toolset("ld", "ld.lld", "ld.lld")
    set_toolset("sh", "clang++", "clang")
    set_toolset("ar", "ar")
    set_toolset("ex", "ar")
    set_toolset("strip", "strip")
    set_toolset("mm", "clang")
    set_toolset("mxx", "clang", "clang++")
    set_toolset("as", "clang")

    add_defines("DARWINBOOT")

    on_check(function (toolchain)
        local ret = import("lib.detect.find_tool")("ld.lld")
        if ret then
            return import("lib.detect.find_tool")("clang")
        else
            return nil
        end
    end)

    on_load(function (toolchain)
        toolchain:add("cflags", "-nostdlib -nostdlibinc -target $(arch)-none-eabi -fno-stack-protector -fno-stack-clash-protection -fno-strict-aliasing -fno-stack-check -fshort-wchar -mno-red-zone -Wno-incompatible-library-redeclaration -ffreestanding -Wno-builtin-requires-header -Wno-incompatible-library-redeclaration -mno-stack-arg-probe")
        toolchain:add("asflags", "-target $(arch)-none-eabi")
        toolchain:add("includedirs", "$(projectdir)/DarwinBoot/include")
    end)
toolchain_end()
