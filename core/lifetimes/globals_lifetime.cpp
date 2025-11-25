#include "globals_lifetime.hpp"

#include <spdlog/spdlog.h>

#include "globals/acm.hpp"
#include "globals/debug.hpp"
#include "globals/ignored_futures.hpp"
#include "globals/tasks.hpp"

void GlobalsLifetime::onStartup() {
#ifdef DEBUG
    g::debug = std::make_unique<g::DebugState>();
#endif

    g::acm = std::make_unique<g::AcmState>();
    g::ignoredFutures = std::make_unique<g::IgnoredFutures>();
    g::tasks = std::make_unique<g::Tasks>();
    spdlog::debug("Global variables initialized");
}

void GlobalsLifetime::onShutdown() {
    spdlog::debug("Destroying global variables...");
    g::tasks.reset();
    g::ignoredFutures.reset();
    g::acm.reset();

#ifdef DEBUG
    g::debug.reset();
#endif
    spdlog::debug("Global variables destroyed");
}
