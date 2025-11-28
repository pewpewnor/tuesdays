#ifdef DEBUG
#include "debug_key_handler.hpp"

#include "globals/engine_state.hpp"
#include "states/debug_state.hpp"

void DebugKeyHandler::onRender() {
    debug::state->showImguiDemoWindow =
        f1Andf2Key_.combineKeyPressAndKeyHeld(debug::state->showImguiDemoWindow);

    if (f5Key_.hasBeenPressed()) {
        g::engine->sendRestartSignal();
    }
}
#endif
