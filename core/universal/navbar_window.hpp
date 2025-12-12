#pragma once

#include <imgui.h>

#include "commons/window_render_step.hpp"

class NavbarWindow : public WindowRenderStep {
public:
    bool beginWindow() override;

    void renderWindowContent() override;
};
