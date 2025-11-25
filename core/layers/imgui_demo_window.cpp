#ifdef DEBUG
#include "imgui_demo_window.hpp"

#include "globals/debug.hpp"

bool ImguiDemoWindow::shouldRender() { return g::debug->showImguiDemoWindow; }

void ImguiDemoWindow::onRender() { ImGui::ShowDemoWindow(&g::debug->showImguiDemoWindow); }
#endif
