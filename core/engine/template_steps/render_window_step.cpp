#include "render_window_step.hpp"

#include <imgui.h>

void engine::RenderWindowStep::onRender() {
    if (beginWindow()) {
        renderWindowContent();
    }
    ImGui::End();
}
