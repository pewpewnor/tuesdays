#ifdef DEBUG
#include "debug_info_overlay_window.hpp"

#include "states/debug_state.hpp"
#include "utils/imgui/window_flags_builder.hpp"

bool DebugInfoOverlayWindow::beginWindow() {
    ImGui::SetNextWindowPos({ImGui::GetMainViewport()->WorkSize.x, 0}, ImGuiCond_Always, {1, 0});
    ImGui::SetNextWindowSize({0, 0});
    ImGuiWindowFlags windowFlags = WindowFlagsBuilder().addStatic().addNoBackground().build();
    return ImGui::Begin("DebugOverlayWindow", nullptr, windowFlags);
}

void DebugInfoOverlayWindow::renderWindowContent() {
    ImGui::Text("Frame Count = %u | FPS = %d ", ++debug::state->frameCount,
                static_cast<int>(ImGui::GetIO().Framerate));
}
#endif
