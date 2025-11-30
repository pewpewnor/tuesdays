target("tuesdays-modules-commons")
    add_files("commons/**.cpp")
    add_deps("tuesdays-core")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-modules-universal")
    add_files("universal/**.cpp")
    add_includedirs(".")
    add_deps("tuesdays-modules-commons", "tuesdays-core")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-modules-debug")
    add_files("debug/**.cpp")
    add_includedirs(".")
    add_deps("tuesdays-modules-commons", "tuesdays-core")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-modules-iws")
    add_files("iws/**.cpp")
    add_includedirs(".")
    add_deps("tuesdays-modules-universal", "tuesdays-modules-commons", "tuesdays-core")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-modules")
    add_includedirs(".", { public = true })
    add_deps(
        "tuesdays-modules-commons",
        "tuesdays-modules-universal",
        "tuesdays-modules-debug",
        "tuesdays-modules-iws"
    )
