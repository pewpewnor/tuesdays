#pragma once

#include <imgui.h>

#include "commons/window_render_step.hpp"

class NavbarWindow : public commons::WindowRenderStep {
public:
    bool beginWindow() override;

    void renderWindowContent() override;
};
