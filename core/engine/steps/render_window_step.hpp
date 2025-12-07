#pragma once

#include <imgui.h>

#include "render_step.hpp"

namespace engine {

class RenderWindowStep : public virtual engine::RenderStep {
public:
    ImVec2 windowPos;
    ImVec2 windowSize;
    ImVec2 windowPadding;

    RenderWindowStep() = default;
    RenderWindowStep(const RenderWindowStep&) = default;
    RenderWindowStep(RenderWindowStep&&) = delete;
    RenderWindowStep& operator=(const RenderWindowStep&) = default;
    RenderWindowStep& operator=(RenderWindowStep&&) = delete;
    ~RenderWindowStep() override = default;

    void onRender() override;

private:
    virtual bool beginWindow() = 0;

    virtual void renderWindowContent();
};

}
