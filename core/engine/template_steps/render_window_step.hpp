#pragma once

#include "engine/render_step.hpp"

namespace engine {

class RenderWindowStep : public virtual engine::RenderStep {
public:
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

}
