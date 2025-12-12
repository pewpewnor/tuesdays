#include "window_render_step.hpp"

void WindowRenderStep::onRender() {
    if (beginWindow()) {
        renderWindowContent();
    }
    windowPos = ImGui::GetWindowPos();
    windowSize = ImGui::GetWindowSize();
    ImGui::End();
}

void WindowRenderStep::renderWindowContent() {}
