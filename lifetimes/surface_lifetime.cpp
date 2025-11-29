#include "surface_lifetime.hpp"

#include <imgui-SFML.h>
#include <spdlog/spdlog.h>

#include "globals/engine_state.hpp"

void SurfaceLifetime::onStartup() {
    spdlog::debug("Creating window & initializing ImGui...");
    g::engine->window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}),
        "Tuesdays");
    windowInitialized_ = true;
    g::engine->window->clear(sf::Color::Black);  // TODO: remove and add loading screen onStartup
    g::engine->window->setVerticalSyncEnabled(true);

    if (!ImGui::SFML::Init(*g::engine->window)) {
        throw std::runtime_error("failed to initialize imgui-sfml");
    }
    imguiInitialized_ = true;
    spdlog::debug("Window & ImGui initialized");
}

void SurfaceLifetime::onShutdown() {
    spdlog::debug("Closing window & shutting down ImGui...");
    if (windowInitialized_) {
        g::engine->window->close();
        windowInitialized_ = false;
    }
    if (imguiInitialized_) {
        ImGui::SFML::Shutdown();
        imguiInitialized_ = false;
    }
}
