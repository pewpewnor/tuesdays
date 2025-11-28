#pragma once

#include "engine/render_step.hpp"

class GlobalKeyHandler : public engine::RenderStep {
public:
    void onRender() override;
};
