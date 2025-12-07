#include "univ_lifetime.hpp"

#include "states/universal_state.hpp"

void UnivLifetime::onStartup() { univ::state = std::make_unique<univ::UniversalState>(); }

void UnivLifetime::onShutdown() { univ::state.reset(); }
