#ifdef DEBUG
#pragma once

#include "commons/window_render_step.hpp"

class DebugInfoOverlayWindow : public commons::WindowRenderStep {
public:
    bool begin() override;

    void renderContent() override;
};
#endif
