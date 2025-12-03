#include "render_window_step.hpp"

void commons::RenderWindowStep::renderWindowContent() {}

void commons::RenderWindowStep::onRender() {
    if (beginWindow()) {
        renderWindowContent();
    }
    windowPos = ImGui::GetWindowPos();
    windowSize = ImGui::GetWindowSize();
    ImGui::End();
}
