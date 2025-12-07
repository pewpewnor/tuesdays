#pragma once

#include <imgui.h>

class ChildWindowFlagsBuilder {
public:
    consteval ChildWindowFlagsBuilder() = default;

    consteval ChildWindowFlagsBuilder add(ImGuiChildFlags flag) {
        flags_ = static_cast<ImGuiWindowFlags>(static_cast<unsigned int>(flags_) |
                                               static_cast<unsigned int>(flag));
        return *this;
    }

    consteval ChildWindowFlagsBuilder addAlwaysUseWindowPadding() {
        return this->add(ImGuiChildFlags_AlwaysUseWindowPadding);
    }

    consteval ChildWindowFlagsBuilder addAutoResizeY() {
        return this->add(ImGuiChildFlags_AutoResizeY);
    }

    consteval ImGuiWindowFlags build() { return flags_; }

private:
    ImGuiWindowFlags flags_;
};
