#pragma once

#include "engine/render_step.hpp"

class IwsModalCreateServer : public engine::RenderStep {
public:
    bool shouldRender() override;

    void onRender() override;
};
