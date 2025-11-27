#include "global_states_lifetime.hpp"

#include <spdlog/spdlog.h>

#include "globals/acm.hpp"
#include "globals/debug.hpp"
#include "globals/universal.hpp"

void GlobalStatesLifetime::onStartup() {
    spdlog::debug("Initializing global states...");
#ifdef DEBUG
    debug::state = std::make_unique<debug::DebugState>();
#endif
    univ::state = std::make_unique<univ::UniversalState>();
    acm::state = std::make_unique<acm::AcmState>();
    spdlog::debug("Global states initialized");
}

void GlobalStatesLifetime::onShutdown() {
    spdlog::debug("Destroying global states...");
    acm::state.reset();
    univ::state.reset();
#ifdef DEBUG
    debug::state.reset();
#endif
    spdlog::debug("Global states destroyed");
}
