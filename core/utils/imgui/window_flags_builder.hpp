#pragma once

#include "imgui.h"

class WindowFlagsBuilder {
public:
    WindowFlagsBuilder add(ImGuiWindowFlags_ flag);

    ImGuiWindowFlags build();

private:
    ImGuiWindowFlags flags_;
};
