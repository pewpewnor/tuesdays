target("tuesdays-layers-components")
    add_files("components/**.cpp")
    add_deps("tuesdays-core")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-layers-universal")
    add_files("universal/**.cpp")
    add_includedirs(".")
    add_deps("tuesdays-core")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-layers-debug")
    add_files("debug/**.cpp")
    add_includedirs(".")
    add_deps("tuesdays-core")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-layers-iws")
    add_files("iws/**.cpp")
    add_includedirs(".")
    add_deps("tuesdays-layers-universal", "tuesdays-core")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-layers")
    add_includedirs(".", { public = true })
    add_deps(
        "tuesdays-layers-components",
        "tuesdays-layers-universal",
        "tuesdays-layers-debug",
        "tuesdays-layers-iws"
    )
