#include "application.hpp"

#include <spdlog/spdlog.h>

#include <memory>

#include "engine/engine.hpp"
#include "globals/engine_state.hpp"
#include "keys/debug_key_handler.hpp"
#include "keys/global_key_handler.hpp"
#include "layers/acm_menubar.hpp"
#include "layers/acm_sidebar.hpp"
#include "layers/debug_info_overlay.hpp"
#include "layers/imgui_demo_window.hpp"
#include "layers/navbar.hpp"
#include "layers/topbar.hpp"
#include "lifetimes/default_imgui_styling.hpp"
#include "lifetimes/fonts_lifetime.hpp"
#include "lifetimes/global_states_lifetime.hpp"
#include "lifetimes/surface_lifetime.hpp"
#include "lifetimes/tasks_lifetime.hpp"
#include "lifetimes/textures_lifetime.hpp"
#include "utils/assertions.hpp"

Application::Application() {
    g::engine = std::make_unique<engine::Engine>();

    pushLifetimeSteps();
    pushKeyHandlerSteps();
    pushRenderSteps();
}

Application::~Application() { g::engine.reset(); }

void Application::start() {
    ASSERT(g::engine, "only execute application with engine existing");
    spdlog::info("Running application...");
    g::engine->runContinously();
    spdlog::info("Application stopped");
}

void Application::requestStop() {
    if (g::engine) {
        g::engine->sendStopSignal();
    }
}

void Application::pushLifetimeSteps() {
    auto globalStatesLifetime = std::make_shared<GlobalStatesLifetime>();
    g::engine->pushStartupStep(globalStatesLifetime);
    g::engine->pushShutdownStep(globalStatesLifetime);

    auto tasksLifetime = std::make_shared<TasksLifetime>();
    g::engine->pushStartupStep(tasksLifetime);
    g::engine->pushShutdownStep(tasksLifetime);

    auto texturesLifetime = std::make_shared<TexturesLifetime>();
    g::engine->pushStartupStep(texturesLifetime);
    g::engine->pushShutdownStep(texturesLifetime);

    auto surfaceLifetime = std::make_shared<SurfaceLifetime>();
    g::engine->pushStartupStep(surfaceLifetime);
    g::engine->pushShutdownStep(surfaceLifetime);

    auto fontsLifetime = std::make_shared<FontsLifetime>();
    g::engine->pushStartupStep(fontsLifetime);
    g::engine->pushShutdownStep(fontsLifetime);

    g::engine->pushStartupStep(std::make_shared<DefaultImguiStyling>());
}

void Application::pushKeyHandlerSteps() {
#ifdef DEBUG
    g::engine->pushRenderStep(std::make_shared<DebugKeyHandler>());
#endif

    g::engine->pushRenderStep(std::make_shared<GlobalKeyHandler>());
}

void Application::pushRenderSteps() {
    auto navbar = std::make_shared<Navbar>();
    auto topbar = std::make_shared<Topbar>(navbar);
    auto acmMenubar = std::make_shared<AcmMenubar>(topbar);
    auto acmSidebar = std::make_shared<AcmSidebar>(navbar, topbar);

    g::engine->pushRenderStep(navbar);
    g::engine->pushRenderStep(topbar);
    g::engine->pushRenderStep(acmMenubar);
    g::engine->pushRenderStep(acmSidebar);

#ifdef DEBUG
    g::engine->pushRenderStep(std::make_shared<ImguiDemoWindow>());
    g::engine->pushRenderStep(std::make_shared<DebugInfoOverlay>());
#endif
}
