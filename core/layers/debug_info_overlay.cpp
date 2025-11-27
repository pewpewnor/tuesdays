#ifdef DEBUG
#include "debug_info_overlay.hpp"

#include "globals/debug.hpp"
#include "utils/imgui/window_flags_builder.hpp"

void DebugInfoOverlay::onRender() {
    ImGui::SetNextWindowPos({ImGui::GetMainViewport()->WorkSize.x, 0}, ImGuiCond_Always, {1, 0});
    ImGui::SetNextWindowSize({0, 0});
    ImGuiWindowFlags windowFlags = WindowFlagsBuilder().addPlain().addNoBackground().build();
    ImGui::Begin("DebugOverlay", nullptr, windowFlags);

    ImGui::Text("Frame Count = %u | FPS = %d", ++debug::state->frameCount,
                static_cast<int>(ImGui::GetIO().Framerate));

    ImGui::End();
}
#endif
