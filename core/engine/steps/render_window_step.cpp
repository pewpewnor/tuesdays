#include "render_window_step.hpp"

void engine::RenderWindowStep::renderWindowContent() {}

void engine::RenderWindowStep::onRender() {
    if (beginWindow()) {
        renderWindowContent();
    }
    windowPos = ImGui::GetWindowPos();
    windowSize = ImGui::GetWindowSize();
    ImGui::End();
}
