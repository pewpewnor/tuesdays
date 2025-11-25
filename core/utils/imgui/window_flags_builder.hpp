#pragma once

#include <imgui.h>

class WindowFlagsBuilder {
public:
    consteval WindowFlagsBuilder() = default;

    consteval WindowFlagsBuilder add(ImGuiWindowFlags_ flag) {
        flags_ = static_cast<ImGuiWindowFlags>(static_cast<unsigned int>(flags_) |
                                               static_cast<unsigned int>(flag));
        return *this;
    }

    consteval WindowFlagsBuilder addStatic() {
        return this->add(ImGuiWindowFlags_NoDecoration)
            .add(ImGuiWindowFlags_NoResize)
            .add(ImGuiWindowFlags_NoMove)
            .add(ImGuiWindowFlags_NoBringToFrontOnFocus)
            .add(ImGuiWindowFlags_NoFocusOnAppearing)
            .add(ImGuiWindowFlags_NoCollapse)
            .add(ImGuiWindowFlags_NoSavedSettings);
    }

    consteval ImGuiWindowFlags build() { return flags_; }

private:
    ImGuiWindowFlags flags_;
};
