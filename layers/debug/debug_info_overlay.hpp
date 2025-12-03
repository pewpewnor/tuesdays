#ifdef DEBUG
#pragma once

#include "commons/steps/render_window_step.hpp"

class DebugInfoOverlay : public commons::RenderWindowStep {
public:
    bool beginWindow() override;

    void renderWindowContent() override;
};
#endif
