#pragma once

#include <imgui_internal.h>

class BringWindowToFrontOnce {
public:
    void bringToFrontIfFirstTime() {
        if (firstTime_) {
            ImGui::BringWindowToDisplayFront(ImGui::GetCurrentWindow());
            firstTime_ = false;
        }
    }

private:
    bool firstTime_ = true;
};
