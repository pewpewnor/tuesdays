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
        return this->addNoResize()
            .addNoMove()
            .addNoCollapse()
            .addNoDecoration()
            .addNoSavedSettings();
    }

    consteval WindowFlagsBuilder addMenuBar() { return this->add(ImGuiWindowFlags_MenuBar); }

    consteval WindowFlagsBuilder addAlwaysAutoResize() {
        return this->add(ImGuiWindowFlags_AlwaysAutoResize);
    }

    consteval WindowFlagsBuilder addNoResize() { return this->add(ImGuiWindowFlags_NoResize); }

    consteval WindowFlagsBuilder addNoMove() { return this->add(ImGuiWindowFlags_NoMove); }

    consteval WindowFlagsBuilder addNoCollapse() { return this->add(ImGuiWindowFlags_NoCollapse); }

    consteval WindowFlagsBuilder addNoInputs() { return this->add(ImGuiWindowFlags_NoInputs); }

    consteval WindowFlagsBuilder addNoDecoration() {
        return this->add(ImGuiWindowFlags_NoDecoration);
    }

    consteval WindowFlagsBuilder addNoBackground() {
        return this->add(ImGuiWindowFlags_NoBackground);
    }

    // window will be behind other windows on spawn & can't be on top of other windows
    consteval WindowFlagsBuilder addNoBringToFrontOnFocus() {
        return this->add(ImGuiWindowFlags_NoBringToFrontOnFocus);
    }

    consteval WindowFlagsBuilder addNoFocusOnAppearing() {
        return this->add(ImGuiWindowFlags_NoFocusOnAppearing);
    }

    consteval WindowFlagsBuilder addNoSavedSettings() {
        return this->add(ImGuiWindowFlags_NoSavedSettings);
    }

    consteval ImGuiWindowFlags build() { return flags_; }

private:
    ImGuiWindowFlags flags_;
};
