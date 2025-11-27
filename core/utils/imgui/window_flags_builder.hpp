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
        return this->add(ImGuiWindowFlags_NoResize)
            .add(ImGuiWindowFlags_NoMove)
            .add(ImGuiWindowFlags_NoCollapse)
            .add(ImGuiWindowFlags_NoSavedSettings);
    }

    consteval WindowFlagsBuilder addPlain() { return this->addStatic().addNoDecoration(); }

    consteval WindowFlagsBuilder addNoDecoration() {
        return this->add(ImGuiWindowFlags_NoDecoration);
    }

    consteval WindowFlagsBuilder addNoBackground() {
        return this->add(ImGuiWindowFlags_NoBackground);
    }

    // Window will be behind other windows on spawn & can't be on top of other windows
    consteval WindowFlagsBuilder addNoBringToFrontOnFocus() {
        return this->add(ImGuiWindowFlags_NoBringToFrontOnFocus);
    }

    consteval ImGuiWindowFlags build() { return flags_; }

private:
    ImGuiWindowFlags flags_;
};
