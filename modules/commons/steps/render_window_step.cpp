#include "render_window_step.hpp"

void RenderWindowStep::onRender() {
    if (beginWindow()) {
        renderWindowContent();
    }
    windowPos = ImGui::GetWindowPos();
    windowSize = ImGui::GetWindowSize();
    ImGui::End();
}
