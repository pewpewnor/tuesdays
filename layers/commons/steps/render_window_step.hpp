#pragma once

#include <imgui.h>

#include "engine/render_step.hpp"

class RenderWindowStep : public virtual engine::RenderStep {
public:
    ImVec2 windowPos;
    ImVec2 windowSize;

    RenderWindowStep() = default;
    RenderWindowStep(const RenderWindowStep&) = default;
    RenderWindowStep(RenderWindowStep&&) = delete;
    RenderWindowStep& operator=(const RenderWindowStep&) = default;
    RenderWindowStep& operator=(RenderWindowStep&&) = delete;
    ~RenderWindowStep() override = default;

    virtual bool beginWindow() = 0;

    virtual void renderWindowContent();

    void onRender() override;
};
