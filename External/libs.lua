target("libprintf")
    set_basename("printf")
    add_includedirs("$(projectdir)/DarwinBoot/include")
    set_languages("c17")
    set_kind("static")

    if is_plat("uefi") then
        set_prefixname("")
        set_extension(".lib")
    end

    add_files(
        "$(projectdir)/External/printf/printf.c"
    )

    add_defines("PRINTF_DISABLE_SUPPORT_FLOAT=1", "PRINTF_DISABLE_SUPPORT_EXPONENTIAL=1")
