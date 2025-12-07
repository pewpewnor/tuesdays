#include "application.hpp"

#include <spdlog/spdlog.h>

#include <memory>

#include "debug/debug_info_overlay.hpp"
#include "debug/debug_key_handler.hpp"
#include "debug/debug_lifetime.hpp"
#include "debug/imgui_demo_window.hpp"
#include "engine/engine.hpp"
#include "globals/engine_state.hpp"
#include "iws/iws.hpp"
#include "lifetimes/asset_loaders/fonts_lifetime.hpp"
#include "lifetimes/asset_loaders/textures_lifetime.hpp"
#include "lifetimes/ignored_tasks_lifetime.hpp"
#include "lifetimes/initializers/default_imgui_styling.hpp"
#include "lifetimes/surface_lifetime.hpp"
#include "universal/navbar.hpp"
#include "universal/topbar.hpp"
#include "universal/univ_lifetime.hpp"
#include "utils/assertions.hpp"

Application::Application() {
    g::engine = std::make_unique<engine::Engine>();

    pushLifetimeSteps();
    pushKeyHandlerSteps();
    pushUiSteps();
}

Application::~Application() { g::engine.reset(); }

void Application::start() {
    ASSERT(g::engine, "only execute application with engine existing");
    spdlog::info("Running application ...");
    g::engine->runContinously();
    spdlog::info("Application stopped");
}

void Application::requestStop() {
    if (g::engine) {
        g::engine->sendStopSignal();
    }
}

void Application::pushLifetimeSteps() {
    auto texturesLifetime = std::make_shared<TexturesLifetime>();
    g::engine->pushStartupStep(texturesLifetime);
    g::engine->pushShutdownStep(texturesLifetime);

    auto surfaceLifetime = std::make_shared<SurfaceLifetime>();
    g::engine->pushStartupStep(surfaceLifetime);
    g::engine->pushShutdownStep(surfaceLifetime);

    auto fontsLifetime = std::make_shared<FontsLifetime>();
    g::engine->pushStartupStep(fontsLifetime);
    g::engine->pushShutdownStep(fontsLifetime);

    auto ignoredTasksLifetime = std::make_shared<IgnoredTasksLifetime>();
    g::engine->pushStartupStep(ignoredTasksLifetime);
    g::engine->pushShutdownStep(ignoredTasksLifetime);

    g::engine->pushStartupStep(std::make_shared<DefaultImguiStyling>());
}

void Application::pushKeyHandlerSteps() {
#ifdef DEBUG
    g::engine->pushRenderStep(std::make_shared<DebugKeyHandler>());
#endif
}

void Application::pushUiSteps() {
    auto univLifetime = std::make_shared<UnivLifetime>();
    g::engine->pushStartupStep(univLifetime);
    g::engine->pushShutdownStep(univLifetime);
#ifdef DEBUG
    auto debugLifetime = std::make_shared<DebugLifetime>();
    g::engine->pushStartupStep(debugLifetime);
    g::engine->pushShutdownStep(debugLifetime);
#endif

    auto navbar = std::make_shared<Navbar>();
    g::engine->pushRenderStep(navbar);
    auto topbar = std::make_shared<Topbar>(navbar);
    g::engine->pushRenderStep(topbar);

    auto iws = std::make_shared<Iws>(navbar, topbar);
    g::engine->pushGroupStep(iws);

#ifdef DEBUG
    g::engine->pushRenderStep(std::make_shared<ImguiDemoWindow>());
    g::engine->pushRenderStep(std::make_shared<DebugInfoOverlay>());
#endif
}
