#pragma once

namespace engine {

class RenderStep {
public:
    RenderStep() = default;
    RenderStep(const RenderStep&) = default;
    RenderStep(RenderStep&&) = delete;
    RenderStep& operator=(const RenderStep&) = default;
    RenderStep& operator=(RenderStep&&) = delete;
    virtual ~RenderStep() = default;

    void render();

private:
    virtual bool shouldRender();

    virtual void onRender() = 0;
};

}
