#ifdef DEBUG
#include "debug_key_handler.hpp"

#include "globals/debug.hpp"
#include "globals/engine_state.hpp"

void DebugKeyHandler::onRender() {
    g::debug->showImguiDemoWindow =
        f1Andf2Key_.combineKeyPressAndKeyHeld(g::debug->showImguiDemoWindow);

    if (f5Key_.hasBeenPressed()) {
        g::engine->sendRestartSignal();
    }
}
#endif
