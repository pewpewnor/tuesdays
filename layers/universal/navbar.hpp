#pragma once

#include <imgui.h>

#include "commons/steps/render_window_step.hpp"

class Navbar : public commons::RenderWindowStep {
public:
    bool beginWindow() override;

    void renderWindowContent() override;
};
