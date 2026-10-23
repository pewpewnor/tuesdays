# Tuesdays

Tuesdays is a C++ desktop application prototype for organizing API work in collections. Its ImGui interface includes collection and request menus, a sidebar, workspace panels, and server-creation UI. The codebase is being developed as a modular desktop app rather than a finished end-user product.

## Stack

C++23, Xmake, SFML with Dear ImGui, and spdlog. The project also declares OpenSSL, cpp-httplib, and nlohmann-json packages for its evolving API/server workflow.

## Build and run

Install Xmake and a Clang toolchain. Configure and build from the repository root:

~~~sh
xmake f -m debug
xmake
xmake r tuesdays-app
~~~

The Xmake package requirements are fetched during configuration. Debug mode enables address, undefined-behavior, and leak sanitizers where supported. Use `xmake f -m release` for a release build.
