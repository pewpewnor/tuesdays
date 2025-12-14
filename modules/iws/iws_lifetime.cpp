#include "iws_lifetime.hpp"

#include "spdlog/spdlog.h"
#include "states/iws_state.hpp"
#include "states/iws_ui.hpp"

void IwsLifetime::onStartup() {
    spdlog::debug("Initializing Iws ...");
    iws::state = std::make_unique<iws::IwsState>();
    iws::ui = std::make_unique<iws::IwsUi>();

    iws::ui->serverChildWindows.emplace_back(std::make_shared<iws::Server>("alpha"));
    iws::ui->serverChildWindows.emplace_back(std::make_shared<iws::Server>("bravo"));
}

void IwsLifetime::onShutdown() {
    spdlog::debug("Deinitializing Iws ...");
    iws::ui.reset();
    iws::state.reset();
}
