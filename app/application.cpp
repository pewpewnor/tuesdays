#include "application.hpp"

#include <spdlog/spdlog.h>

#include <memory>

#include "engine/engine.hpp"
#include "engine/engine_config.hpp"
#include "globals/engine_state.hpp"
#include "keys/debug_key_handler.hpp"
#include "layers/debug_info_overlay.hpp"
#include "layers/imgui_demo_window.hpp"
#include "lifetimes/globals_lifetime.hpp"
#include "lifetimes/surface_lifetime.hpp"
#include "utils/assertions.hpp"

Application::Application() {
    g::engine = std::make_unique<engine::Engine>(engine::EngineConfig{false, 60, 20});

    pushLifetimeSteps();
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
    auto globalsLifetime = std::make_shared<GlobalsLifetime>();
    auto surfaceLifetime = std::make_shared<SurfaceLifetime>("Tuesdays", 1280, 720);

    g::engine->extendStartupSteps({globalsLifetime, surfaceLifetime});
    g::engine->extendShutdownSteps({globalsLifetime, surfaceLifetime});
}

void Application::pushRenderSteps() {
#ifdef DEBUG
    g::engine->pushRenderStep(std::make_shared<DebugKeyHandler>());
#endif

#ifdef DEBUG
    g::engine->pushRenderStep(std::make_shared<ImguiDemoWindow>());
    g::engine->pushRenderStep(std::make_shared<DebugInfoOverlay>());
#endif
}
