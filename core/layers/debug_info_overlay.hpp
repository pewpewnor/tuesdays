#ifdef DEBUG
#pragma once

#include <imgui.h>

#include "engine/render_step.hpp"

class DebugInfoOverlay : public engine::RenderStep {
public:
    void onRender() override;
};
#endif
