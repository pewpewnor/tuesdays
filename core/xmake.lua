target("tuesdays-core-utils")
    add_files("utils/**.cpp")
    add_includedirs(".")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-core-engine")
    add_files("engine/**.cpp")
    add_includedirs(".")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-core")
    add_includedirs(".", { public = true })
    add_deps(
        "tuesdays-core-utils",
        "tuesdays-core-engine"
    )
