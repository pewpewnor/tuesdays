#include "bring_window_to_front_once.hpp"

#include <imgui_internal.h>

void BringWindowToFrontOnce::bringToFrontIfFirstTime() {
    if (firstTime_) {
        ImGui::BringWindowToDisplayFront(ImGui::GetCurrentWindow());
        firstTime_ = false;
    }
}
