#ifdef DEBUG
#pragma once

#include <imgui.h>

#include "engine/render_step.hpp"

class ImguiDemoWindow : public engine::RenderStep {
public:
    bool shouldRender() override;

    void onRender() override;
};
#endif
