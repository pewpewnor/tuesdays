#include "globals/debug.hpp"
#ifdef DEBUG
#include "debug_info_overlay.hpp"
#include "utils/imgui/window_flags_builder.hpp"

void DebugInfoOverlay::onRender() {
    ImGui::SetNextWindowPos({ImGui::GetMainViewport()->WorkSize.x, 0}, ImGuiCond_Always, {1, 0});
    ImGui::SetNextWindowSize({0, 0}, ImGuiCond_Always);
    ImGuiWindowFlags windowFlags =
        WindowFlagsBuilder().addStatic().add(ImGuiWindowFlags_NoBackground).build();
    ImGui::Begin("DebugOverlay", nullptr, windowFlags);

    ImGui::Text("Frame Count = %u | FPS = %d", ++g::debug->frameCount,
                static_cast<int>(ImGui::GetIO().Framerate));

    ImGui::End();
}
#endif
