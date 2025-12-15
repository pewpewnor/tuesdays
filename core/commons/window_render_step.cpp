#include "window_render_step.hpp"

void commons::WindowRenderStep::onRender() {
    if (beginWindow()) {
        renderWindowContent();
    }
    windowPos = ImGui::GetWindowPos();
    windowSize = ImGui::GetWindowSize();
    ImGui::End();
}

void commons::WindowRenderStep::renderWindowContent() {}
