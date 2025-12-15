#pragma once

#include <imgui.h>

#include "commons/part.hpp"
#include "engine/steps/render_step.hpp"

namespace commons {

class WindowRenderStep : public virtual engine::RenderStep, public virtual commons::Part {
public:
    WindowRenderStep() = default;
    WindowRenderStep(const WindowRenderStep&) = default;
    WindowRenderStep(WindowRenderStep&&) = delete;
    WindowRenderStep& operator=(const WindowRenderStep&) = default;
    WindowRenderStep& operator=(WindowRenderStep&&) = delete;
    ~WindowRenderStep() override = default;

private:
    void onRender() override;

    void end() override;
};

}
