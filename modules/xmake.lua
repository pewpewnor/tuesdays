target("tuesdays-modules-layout")
    add_files("layout/**.cpp")
    add_deps("tuesdays-core")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-modules-iws")
    add_files("iws/**.cpp")
    add_includedirs(".")
    add_deps("tuesdays-core")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-modules")
    add_includedirs(".", { public = true })
    add_deps("tuesdays-modules-iws", "tuesdays-modules-layout")
