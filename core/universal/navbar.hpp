#pragma once

#include <imgui.h>

#include "engine/steps/render_window_step.hpp"

class Navbar : public engine::RenderWindowStep {
public:
    bool beginWindow() override;

    void renderWindowContent() override;
};
