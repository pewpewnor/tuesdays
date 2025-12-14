#ifdef DEBUG
#include "debug_lifetime.hpp"

#include "states/debug_state.hpp"

void DebugLifetime::onStartup() { debug::state = std::make_unique<debug::DebugState>(); }

void DebugLifetime::onShutdown() { debug::state.reset(); }
#endif
