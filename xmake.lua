set_languages("c++23")
set_warnings("allextra", "pedantic", "error")
set_toolchains("clang")
set_runtimes("c++_static")
set_kind("shared")

add_rules("mode.debug", "mode.tsan", "mode.release")
if is_mode("debug") then
	set_policy("build.sanitizer.address", true)
	set_policy("build.sanitizer.undefined", true)
	set_policy("build.sanitizer.leak", true)
    add_defines("DEBUG")
elseif not is_mode("release") then
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
includes("layers")
includes("lifetimes")

target("tuesdays-app")
    set_kind("binary")
    add_files("app/**.cpp")
    add_deps("tuesdays-lifetimes", "tuesdays-layers", "tuesdays-core")
    add_packages("spdlog")
    add_packages("openssl3") -- TODO: remove
    add_packages("cpp-httplib") -- TODO: remove

    after_build(function(target)
        os.cp(path.join(os.projectdir(), "assets"), target:targetdir())
    end)
