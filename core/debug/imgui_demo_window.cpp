#ifdef DEBUG
#include "imgui_demo_window.hpp"

#include "states/debug_state.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/styles_scoped.hpp"

bool ImguiDemoWindow::shouldRender() { return debug::state->showImguiDemoWindow; }

void ImguiDemoWindow::onRender() {
    StylesScoped windowStyles;
    windowStyles.pushStyleColor(ImGuiCol_WindowBg, COLOR_DARK_GRAY);

    ImGui::ShowDemoWindow(&debug::state->showImguiDemoWindow);
}
#endif
