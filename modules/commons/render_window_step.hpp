#pragma once

#include "engine/render_step.hpp"
#include "imgui.h"

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

    virtual void renderWindowContent() = 0;

    void onRender() override;
};
