#pragma once

#include <imgui.h>

#include "engine/template_steps/render_window_step.hpp"

class Navbar : public engine::RenderWindowStep {
public:
    ImVec2 windowPos;
    ImVec2 windowSize;

    bool beginWindow() override;

    void renderWindowContent() override;
};
