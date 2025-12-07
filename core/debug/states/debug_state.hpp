#ifdef DEBUG
#pragma once

#include <memory>

namespace debug {

struct DebugState {
    unsigned int frameCount = 0;
    bool showImguiDemoWindow = false;
};

inline std::unique_ptr<debug::DebugState> state;

}
#endif
