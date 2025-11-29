#include "global_states_lifetime.hpp"

#include <spdlog/spdlog.h>

#include "acm/states/acm_state.hpp"
#include "debug/states/debug_state.hpp"
#include "iws/states/iws_state.hpp"
#include "universal/states/universal_state.hpp"

void GlobalStatesLifetime::onStartup() {
    spdlog::debug("Initializing global states...");
#ifdef DEBUG
    debug::state = std::make_unique<debug::DebugState>();
#endif
    univ::state = std::make_unique<univ::UniversalState>();
    iws::state = std::make_unique<iws::IwsState>();
    acm::state = std::make_unique<acm::AcmState>();
    spdlog::debug("Global states initialized");
}

void GlobalStatesLifetime::onShutdown() {
    spdlog::debug("Destroying global states...");
    acm::state.reset();
    iws::state.reset();
    univ::state.reset();
#ifdef DEBUG
    debug::state.reset();
#endif
    spdlog::debug("Global states destroyed");
}
