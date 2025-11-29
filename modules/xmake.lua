target("tuesdays-modules-lifetimes")
    add_files("lifetimes/**.cpp")
    add_includedirs(".")
    add_deps("tuesdays-core")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-modules-tasks")
    -- add_files("tasks/**.cpp")
    add_includedirs(".")
    add_deps("tuesdays-core")
    add_packages("imgui", "spdlog", { public = true })

target("tuesdays-modules-debug")
    add_files("debug/**.cpp")
    add_includedirs(".")
    add_deps("tuesdays-core")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-modules-universal")
    add_files("universal/**.cpp")
    add_includedirs(".")
    add_deps("tuesdays-core")
    add_packages("imgui-sfml", "spdlog", { public = true })

--[[ target("tuesdays-modules-acm")
    add_files("acm/**.cpp")
    add_includedirs(".")
    add_deps("tuesdays-core")
    add_packages("imgui-sfml", "spdlog", { public = true }) ]]

target("tuesdays-modules-iws")
    add_files("iws/**.cpp")
    add_includedirs(".")
    add_deps("tuesdays-core")
    add_packages("imgui-sfml", "spdlog", { public = true })

target("tuesdays-modules")
    add_includedirs(".", { public = true })
    add_deps(
        "tuesdays-modules-lifetimes",
        "tuesdays-modules-tasks",
        "tuesdays-modules-debug",
        "tuesdays-modules-universal",
        -- "tuesdays-modules-acm",
        "tuesdays-modules-iws"
    )
