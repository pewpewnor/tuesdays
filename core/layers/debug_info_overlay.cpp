#ifdef DEBUG
#include "debug_info_overlay.hpp"

#include "utils/imgui/window_flags_builder.hpp"

unsigned int DebugInfoOverlay::frameCount = 0;

void DebugInfoOverlay::onRender() {
    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x, 0), ImGuiCond_Always,
                            ImVec2(1, 0));
    ImGui::SetNextWindowSize(ImVec2(0, 0), ImGuiCond_Always);
    ImGuiWindowFlags windowFlags = WindowFlagsBuilder()
                                       .add(ImGuiWindowFlags_NoDecoration)
                                       .add(ImGuiWindowFlags_NoBackground)
                                       .build();
    ImGui::Begin("DebugOverlay", nullptr, windowFlags);

    ImGui::Text("Frame count = %u | FPS = %d", ++frameCount,
                static_cast<int>(ImGui::GetIO().Framerate));

    ImGui::End();
}
#endif
