#ifdef DEBUG
#pragma once

#include "commons/window_render_step.hpp"

class DebugInfoOverlayWindow : public commons::WindowRenderStep {
public:
    bool beginWindow() override;

    void renderWindowContent() override;
};
#endif
