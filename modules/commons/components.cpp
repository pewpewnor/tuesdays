#include "components.hpp"

#include <imgui-SFML.h>

#include "imgui.h"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/styles_scoped.hpp"

bool components::navbarAppImageButton(const char* label, bool isActive, const sf::Texture& icon) {
    constexpr float size = 28;
    constexpr float padding = 10;

    StylesScoped styles;
    styles.pushStyleVar(ImGuiStyleVar_FramePadding, {padding, padding});
    styles.pushStyleVar(ImGuiStyleVar_FrameBorderSize, 4);
    styles.pushStyleVar(ImGuiStyleVar_FrameRounding, 8);
    styles.pushStyleColor(ImGuiCol_Button, isActive ? COLOR_AZURE : COLOR_TRANSPARENT);
    ImVec4 hoverActiveColor = isActive ? COLOR_AZURE : COLOR_CHOCOLATE;
    styles.pushStyleColor(ImGuiCol_ButtonHovered, hoverActiveColor);
    styles.pushStyleColor(ImGuiCol_ButtonActive, hoverActiveColor);
    styles.pushStyleColor(ImGuiCol_Border, isActive ? COLOR_TRANSPARENT : COLOR_DARK_GREY);

    return ImGui::ImageButton(label, icon, {size, size});
}

bool components::beginMenubarMenu(const char* label) {
    ImGuiID storageId = ImGui::GetID(label);
    bool* wasHovered = ImGui::GetStateStorage()->GetBoolRef(storageId, false);
    bool isOpen = ImGui::IsPopupOpen(label);

    StylesScoped menuStyle;
    if (*wasHovered || isOpen) {
        menuStyle.pushStyleColor(ImGuiCol_Text, COLOR_TEXT_FG);
    } else {
        menuStyle.pushStyleColor(ImGuiCol_Text, COLOR_TEXT_MUTED);
    }

    bool result = ImGui::BeginMenu(label);
    *wasHovered = ImGui::IsItemHovered(ImGuiHoveredFlags_RectOnly);
    return result;
}
