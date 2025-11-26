#ifdef DEBUG
#pragma once

#include <memory>

namespace g {

struct DebugState {
    bool showImguiDemoWindow = false;
};

inline std::unique_ptr<g::DebugState> debug;

}
#endif
