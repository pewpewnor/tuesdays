#include "iws_lifetime.hpp"

#include "spdlog/spdlog.h"
#include "states/iws_state.hpp"

void IwsLifetime::onStartup() {
    spdlog::debug("Initializing Iws ...");
    iws::state = std::make_unique<iws::IwsState>();

    auto alpha = std::make_shared<iws::Server>("alpha");
    for (int i = 0; i < 10; i++) {
        alpha->endpoints.emplace_back("");
    }
    iws::state->serverChildWindows.emplace_back(alpha);
    iws::state->serverChildWindows.emplace_back(std::make_shared<iws::Server>("bravo"));
}

void IwsLifetime::onShutdown() {
    spdlog::debug("Deinitializing Iws ...");
    iws::state.reset();
}
