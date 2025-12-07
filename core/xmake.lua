target("tuesdays-core-utils")
    add_files("utils/**.cpp")
    add_includedirs(".")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-core-engine")
    add_files("engine/**.cpp")
    add_includedirs(".")
    add_deps("tuesdays-core-utils")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-core-commons")
    add_files("commons/**.cpp")
    add_includedirs(".")
    add_deps("tuesdays-core-engine")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-core-lifetimes")
    add_files("lifetimes/**.cpp")
    add_includedirs(".")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-core-universal")
    add_files("universal/**.cpp")
    add_includedirs(".")
    add_deps("tuesdays-core-commons", "tuesdays-core-engine", "tuesdays-core-utils")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-core-debug")
    add_files("debug/**.cpp")
    add_includedirs(".")
    add_deps("tuesdays-core-engine", "tuesdays-core-utils")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-core")
    add_includedirs(".", { public = true })
    add_deps(
        "tuesdays-core-debug",
        "tuesdays-core-universal",
        "tuesdays-core-lifetimes",
        "tuesdays-core-commons",
        "tuesdays-core-engine",
        "tuesdays-core-utils"
    )
