#pragma once

#include <imgui.h>

#include "engine/render_step.hpp"

class Navbar : public engine::RenderStep {
public:
    ImVec2 windowPos;
    ImVec2 windowSize;

    void onRender() override;
};
