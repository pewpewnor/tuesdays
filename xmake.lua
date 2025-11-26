set_languages("c++23")
set_warnings("allextra", "pedantic", "error")
set_toolchains("clang")
set_runtimes("c++_static")
set_kind("static")

add_rules("mode.debug", "mode.release")
if is_mode("debug") then
	set_policy("build.sanitizer.address", true)
	set_policy("build.sanitizer.undefined", true)
	set_policy("build.sanitizer.leak", true)
    add_defines("DEBUG")
elseif is_mode("debug_tsan") then
	set_policy("build.sanitizer.thread", true)
    add_defines("DEBUG")
end

add_requires("imgui-sfml")
add_requires("spdlog")

includes("core")

target("tuesdays-core")
    add_includedirs("core", { public = true })
    add_deps(
        "tuesdays-core-utils",
        "tuesdays-core-engine",
        "tuesdays-core-globals",
        "tuesdays-core-lifetimes",
        "tuesdays-core-tasks",
        "tuesdays-core-keys",
        "tuesdays-core-components",
        "tuesdays-core-layers"
    )

target("tuesdays-app")
    set_kind("binary")
    add_files("app/**.cpp")
    add_deps("tuesdays-core")
    add_packages("spdlog")

    after_build(function(target)
        os.cp(path.join(os.projectdir(), "assets"), target:targetdir())
    end)
