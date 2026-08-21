#include "iws_lifetime.hpp"

#include "spdlog/spdlog.h"
#include "states/iws_state.hpp"

void IwsLifetime::onStartup() {
    spdlog::debug("Initializing Iws ...");
    iws::state = std::make_unique<iws::IwsState>();

    auto alpha = std::make_shared<iws::Server>("alpha");
    alpha->endpoints.push_back(std::make_shared<iws::Endpoint>("Get Users"));
    alpha->endpoints.push_back(std::make_shared<iws::Endpoint>("Create User"));
    iws::state->collections.addServer(alpha);

    iws::state->collections.addServer(std::make_shared<iws::Server>("bravo"));
}

void IwsLifetime::onShutdown() {
    spdlog::debug("Deinitializing Iws ...");
    iws::state.reset();
}
