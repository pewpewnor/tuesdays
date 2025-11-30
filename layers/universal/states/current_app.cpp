#include "current_app.hpp"

#include "universal/states/universal_state.hpp"

bool univ::currentAppIsAcm() { return univ::state->currentApp == univ::CurrentApp::Acm; }

bool univ::currentAppIsIws() { return univ::state->currentApp == univ::CurrentApp::Iws; }
