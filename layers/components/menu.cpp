#include "menu.hpp"

#include <imgui.h>

#include "utils/imgui/colors.hpp"
#include "utils/imgui/styles_scoped.hpp"

components::Menu::Menu(const std::string& label) : label_(label) {}

bool components::Menu::begin() {
    const char* label = label_.c_str();

    ImGuiID storageId = ImGui::GetID(label);
    bool* wasHovered = ImGui::GetStateStorage()->GetBoolRef(storageId, false);
    bool isOpen = ImGui::IsPopupOpen(label);

    StylesScoped menuStyles;
    if (!*wasHovered && !isOpen) {
        menuStyles.pushStyleColor(ImGuiCol_Text, COLOR_FG_MUTED);
    }

    bool result = ImGui::BeginMenu(label);
    *wasHovered = ImGui::IsItemHovered(ImGuiHoveredFlags_RectOnly);
    return result;
}

void components::Menu::endOfDisplay() { ImGui::EndMenu(); }
