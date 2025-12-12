#include "iws_lifetime.hpp"

#include "iws/events/update_server_groups.hpp"
#include "spdlog/spdlog.h"
#include "states/iws_state.hpp"
#include "states/iws_ui.hpp"

void IwsLifetime::onStartup() {
    spdlog::debug("Initializing Iws ...");
    iws::state = std::make_unique<iws::IwsState>();
    iws::ui = std::make_unique<iws::IwsUi>();

    iws::state->servers.push_back(std::make_shared<iws::Server>("alpha"));
    iws::state->servers.push_back(std::make_shared<iws::Server>("bravo"));
    iws::events::updateServerGroups();
}

void IwsLifetime::onShutdown() {
    spdlog::debug("Deinitializing Iws ...");
    iws::ui.reset();
    iws::state.reset();
}
