#include "menu_part.hpp"

#include <imgui.h>

#include "globals/engine_state.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/styles_scoped.hpp"

components::MenuPart::MenuPart(const std::string& label) : label_(label) {}

bool components::MenuPart::begin() {
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

void components::MenuPart::endContent() { ImGui::EndMenu(); }
