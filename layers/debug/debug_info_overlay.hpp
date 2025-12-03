#ifdef DEBUG
#pragma once

#include "engine/steps/render_window_step.hpp"

class DebugInfoOverlay : public engine::RenderWindowStep {
public:
    bool beginWindow() override;

    void renderWindowContent() override;
};
#endif
