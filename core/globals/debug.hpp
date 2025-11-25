#pragma once

#ifdef DEBUG
#include <memory>

namespace g {

struct DebugState {
    bool showImguiDemoWindow = false;
};

inline std::unique_ptr<g::DebugState> debug;

}
#endif
