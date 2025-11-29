#include "application.hpp"

#include <spdlog/spdlog.h>

#include <memory>

#include "debug/debug_info_overlay.hpp"
#include "debug/debug_key_handler.hpp"
#include "debug/imgui_demo_window.hpp"
#include "engine/engine.hpp"
#include "globals/engine_state.hpp"
#include "iws/iws_body.hpp"
#include "iws/iws_menubar.hpp"
#include "iws/iws_sidebar.hpp"
#include "lifetimes/asset_loaders/fonts_lifetime.hpp"
#include "lifetimes/asset_loaders/textures_lifetime.hpp"
#include "lifetimes/global_states_lifetime.hpp"
#include "lifetimes/initializers/default_imgui_styling.hpp"
#include "lifetimes/surface_lifetime.hpp"
#include "lifetimes/tasks_lifetime.hpp"
#include "universal/navbar.hpp"
#include "universal/topbar.hpp"
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
}

void Application::pushRenderSteps() {
    auto navbar = std::make_shared<Navbar>();
    auto topbar = std::make_shared<Topbar>(navbar);

    g::engine->pushRenderStep(navbar);
    g::engine->pushRenderStep(topbar);

    /* auto acmMenubar = std::make_shared<AcmMenubar>(topbar);
    auto acmSidebar = std::make_shared<AcmSidebar>(navbar, topbar);
    auto acmBody = std::make_shared<AcmBody>(topbar, acmSidebar);
    g::engine->pushRenderStep(acmMenubar);
    g::engine->pushRenderStep(acmSidebar);
    g::engine->pushRenderStep(acmBody); */

    auto iwsMenubar = std::make_shared<IwsMenubar>(topbar);
    auto iwsSidebar = std::make_shared<IwsSidebar>(navbar, topbar);
    auto iwsBody = std::make_shared<IwsBody>(topbar, iwsSidebar);
    g::engine->pushRenderStep(iwsMenubar);
    g::engine->pushRenderStep(iwsSidebar);
    g::engine->pushRenderStep(iwsBody);

#ifdef DEBUG
    g::engine->pushRenderStep(std::make_shared<ImguiDemoWindow>());
    g::engine->pushRenderStep(std::make_shared<DebugInfoOverlay>());
#endif
}
