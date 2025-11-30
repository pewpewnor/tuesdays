#include "application.hpp"

#include <spdlog/spdlog.h>

#include <memory>

#include "asset_loaders/fonts_lifetime.hpp"
#include "asset_loaders/textures_lifetime.hpp"
#include "debug/debug_info_overlay.hpp"
#include "debug/debug_key_handler.hpp"
#include "debug/imgui_demo_window.hpp"
#include "engine/engine.hpp"
#include "global_states_lifetime.hpp"
#include "globals/engine_state.hpp"
#include "initializers/default_imgui_styling.hpp"
#include "iws/body/iws_body.hpp"
#include "iws/modals/iws_modal_create_server.hpp"
#include "iws/sidebar/iws_servers_filter.hpp"
#include "iws/sidebar/iws_sidebar.hpp"
#include "iws/top/iws_menubar.hpp"
#include "surface_lifetime.hpp"
#include "tasks_lifetime.hpp"
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

    auto iwsMenubar = std::make_shared<IwsMenubar>(topbar);
    g::engine->pushRenderStep(iwsMenubar);

    auto iwsSidebar = std::make_shared<IwsSidebar>(navbar, topbar);
    auto iwsServersFilter = std::make_shared<IwsServersFilter>(iwsSidebar);
    g::engine->pushRenderStep(iwsSidebar);
    g::engine->pushRenderStep(iwsServersFilter);
    g::engine->pushRenderStep(std::make_shared<IwsModalCreateServer>());

    auto iwsBody = std::make_shared<IwsBody>(topbar, iwsSidebar);
    g::engine->pushRenderStep(iwsBody);

#ifdef DEBUG
    g::engine->pushRenderStep(std::make_shared<ImguiDemoWindow>());
    g::engine->pushRenderStep(std::make_shared<DebugInfoOverlay>());
#endif
}
