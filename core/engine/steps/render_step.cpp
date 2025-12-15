#include "render_step.hpp"

void engine::RenderStep::render() {
    if (shouldRender()) {
        onRender();
    }
}

bool engine::RenderStep::shouldRender() { return true; }
