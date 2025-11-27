#ifdef DEBUG
#include "imgui_demo_window.hpp"

#include "globals/debug.hpp"

bool ImguiDemoWindow::shouldRender() { return debug::state->showImguiDemoWindow; }

void ImguiDemoWindow::onRender() { ImGui::ShowDemoWindow(&debug::state->showImguiDemoWindow); }
#endif
