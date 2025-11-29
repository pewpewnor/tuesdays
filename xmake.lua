set_languages("c++23")
set_warnings("allextra", "pedantic", "error")
set_toolchains("clang")
set_runtimes("c++_static")
set_kind("shared")

add_rules("mode.debug", "mode.release")
if is_mode("debug") then
	set_policy("build.sanitizer.address", true)
	set_policy("build.sanitizer.undefined", true)
	set_policy("build.sanitizer.leak", true)
	add_defines("DEBUG")
elseif is_mode("debug_tsan") then
	set_policy("build.sanitizer.thread", true)
	add_defines("DEBUG")
else
	set_kind("static")
end

add_requires("imgui-sfml")
add_requires("openssl3")
add_requires("cpp-httplib")
add_requires("nlohmann_json")
add_requires("spdlog")
add_requireconfs("*", { configs = { shared = not is_mode("release") } })

includes("core")
includes("modules")

target("tuesdays-app")
    set_kind("binary")
    add_files("app/**.cpp")
    add_deps("tuesdays-modules", "tuesdays-core")
    add_packages("spdlog")

    after_build(function(target)
        os.cp(path.join(os.projectdir(), "assets"), target:targetdir())
    end)
