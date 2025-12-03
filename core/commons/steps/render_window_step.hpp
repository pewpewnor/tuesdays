#pragma once

#include <imgui.h>

#include "engine/render_step.hpp"

namespace commons {

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

private:
    virtual bool beginWindow() = 0;

    virtual void renderWindowContent();

    void onRender() override;
};

}
