target("tuesdays-lifetimes-asset_loaders")
    add_files("asset_loaders/**.cpp")
    add_includedirs(".")
    add_deps("tuesdays-modules", "tuesdays-core")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-lifetimes-initializers")
    add_files("initializers/**.cpp")
    add_includedirs(".")
    add_deps("tuesdays-modules", "tuesdays-core")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-lifetimes")
    add_files("*.cpp")
    add_includedirs(".", { public = true })
    add_deps(
        "tuesdays-lifetimes-asset_loaders",
        "tuesdays-lifetimes-initializers",
        "tuesdays-modules",
        "tuesdays-core"
    )
    add_packages("imgui-sfml", "spdlog", { public = true })
