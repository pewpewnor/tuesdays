#ifdef DEBUG
#pragma once
#include <imgui.h>

#include "engine/template_steps/render_window_step.hpp"

class DebugInfoOverlay : public engine::RenderWindowStep {
public:
    bool beginWindow() override;

    void renderWindowContent() override;
};
#endif
