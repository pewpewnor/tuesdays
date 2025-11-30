#include "render_group.hpp"

void RenderGroup::onRender() {
    for (const std::shared_ptr<engine::RenderStep>& renderStep : renderSteps) {
        if (renderStep->shouldRender()) {
            renderStep->onRender();
        }
    }
}
