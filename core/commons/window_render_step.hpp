#pragma once

#include <imgui.h>

#include "engine/steps/render_step.hpp"

class WindowRenderStep : public virtual engine::RenderStep {
public:
    ImVec2 windowPos;
    ImVec2 windowSize;
    ImVec2 windowPadding;

    WindowRenderStep() = default;
    WindowRenderStep(const WindowRenderStep&) = default;
    WindowRenderStep(WindowRenderStep&&) = delete;
    WindowRenderStep& operator=(const WindowRenderStep&) = default;
    WindowRenderStep& operator=(WindowRenderStep&&) = delete;
    ~WindowRenderStep() override = default;

    void onRender() override;

private:
    virtual bool beginWindow() = 0;

    virtual void renderWindowContent();
};
