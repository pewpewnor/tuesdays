#pragma once

#include <memory>
#include <vector>

#include "engine/render_step.hpp"

class RenderGroup : public virtual engine::RenderStep {
public:
    RenderGroup() = default;
    RenderGroup(const RenderGroup&) = default;
    RenderGroup(RenderGroup&&) = delete;
    RenderGroup& operator=(const RenderGroup&) = default;
    RenderGroup& operator=(RenderGroup&&) = delete;
    ~RenderGroup() override = default;

    void onRender() override;

protected:
    std::vector<std::shared_ptr<engine::RenderStep>> renderSteps;
};
