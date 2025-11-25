#ifdef DEBUG
#include "debug_key_handler.hpp"

#include "globals/debug.hpp"

void DebugKeyHandler::onRender() {
    g::debug->showImguiDemoWindow =
        f1Andf2Key_.combineKeyPressAndKeyHeld(g::debug->showImguiDemoWindow);
}
#endif
