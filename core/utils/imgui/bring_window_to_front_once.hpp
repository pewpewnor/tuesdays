#pragma once

#include <imgui_internal.h>

class BringWindowToFrontOnce {
public:
    void checkForCurrentWindow() {
        if (firstTime_) {
            firstTime_ = false;
            ImGui::BringWindowToDisplayFront(ImGui::GetCurrentWindow());
        }
    }

private:
    bool firstTime_ = true;
};
