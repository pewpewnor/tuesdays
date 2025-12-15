#include "window_render_step.hpp"

void commons::WindowRenderStep::onRender() { display(); }

void commons::WindowRenderStep::end() { ImGui::End(); }
