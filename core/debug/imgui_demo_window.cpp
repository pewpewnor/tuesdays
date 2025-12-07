#ifdef DEBUG
#include "imgui_demo_window.hpp"

#include "states/debug_state.hpp"

bool ImguiDemoWindow::shouldRender() { return debug::state->showImguiDemoWindow; }

void ImguiDemoWindow::onRender() { ImGui::ShowDemoWindow(&debug::state->showImguiDemoWindow); }
#endif
