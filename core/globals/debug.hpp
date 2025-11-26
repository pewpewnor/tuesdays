#ifdef DEBUG
#pragma once

#include <memory>

namespace g {

struct DebugState {
    unsigned int frameCount = 0;
    bool showImguiDemoWindow = false;
};

inline std::unique_ptr<g::DebugState> debug;

}
#endif
