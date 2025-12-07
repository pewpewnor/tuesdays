#include "menu.hpp"

#include <imgui.h>

#include "globals/engine_state.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/styles_scoped.hpp"

components::Menu::Menu(const std::string& label) : label_(label) {}

bool components::Menu::begin() {
    const char* label = label_.c_str();

    bool isOpen = ImGui::IsPopupOpen(label);

    StylesScoped menuStyles;
    if (!wasHovered_ && !isOpen) {
        menuStyles.pushStyleColor(ImGuiCol_Text, COLOR_FG_MUTED);
    }

    bool result = ImGui::BeginMenu(label);

    bool hovered = ImGui::IsItemHovered(ImGuiHoveredFlags_RectOnly);
    if (hovered && !wasHovered_) {
        g::engine->sendRefreshSignal();
    }
    wasHovered_ = hovered;

    return result;
}

void components::Menu::endOfDisplay() { ImGui::EndMenu(); }
