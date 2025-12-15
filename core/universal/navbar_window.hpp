#pragma once

#include <imgui.h>

#include "commons/window_render_step.hpp"

class NavbarWindow : public commons::WindowRenderStep {
public:
    ImVec2 windowPos;
    ImVec2 windowSize;

    bool begin() override;

    void renderContent() override;
};
