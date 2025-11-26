#include "global_states_lifetime.hpp"

#include <spdlog/spdlog.h>

#include "globals/acm.hpp"
#include "globals/debug.hpp"

void GlobalStatesLifetime::onStartup() {
    spdlog::debug("Initializing global states...");
#ifdef DEBUG
    g::debug = std::make_unique<g::DebugState>();
#endif
    g::acm = std::make_unique<g::AcmState>();
    spdlog::debug("Global states initialized");
}

void GlobalStatesLifetime::onShutdown() {
    spdlog::debug("Destroying global states...");
    g::acm.reset();
#ifdef DEBUG
    g::debug.reset();
#endif
    spdlog::debug("Global states destroyed");
}
