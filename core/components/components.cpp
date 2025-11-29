#include "components.hpp"

#include <imgui-SFML.h>

#include "utils/imgui/colors.hpp"
#include "utils/imgui/helpers.hpp"
#include "utils/imgui/styles_scoped.hpp"

bool components::navbarAppImageButton(const char* id, bool isActive, const sf::Texture& light,
                                      const sf::Texture& dark) {
    constexpr float size = 28;
    constexpr float padding = 10;
    constexpr float fullSideSize = size + (padding * 2);

    bool isHovered = nextWidgetIsHovered(fullSideSize, fullSideSize);

    StylesScoped styles;
    styles.pushStyleVar(ImGuiStyleVar_FrameRounding, 8);
    styles.pushStyleVar(ImGuiStyleVar_FramePadding, {padding, padding});
    styles.pushStyleColor(ImGuiCol_Button, isActive ? COLOR_AZURE : COLOR_TRANSPARENT);
    ImVec4 hoverActiveColor = isActive ? COLOR_AZURE : COLOR_CHOCOLATE;
    styles.pushStyleColor(ImGuiCol_ButtonHovered, hoverActiveColor);
    styles.pushStyleColor(ImGuiCol_ButtonActive, hoverActiveColor);

    return ImGui::ImageButton(id, isHovered && !isActive ? dark : light, {size, size});
}

bool components::beginMenubarMenu(const char* id) {
    ImGuiID storageId = ImGui::GetID(id);
    bool* wasHovered = ImGui::GetStateStorage()->GetBoolRef(storageId, false);
    bool isOpen = ImGui::IsPopupOpen(id);

    StylesScoped menuStyle;
    if (*wasHovered || isOpen) {
        menuStyle.pushStyleColor(ImGuiCol_Text, COLOR_TEXT_FG);
    } else {
        menuStyle.pushStyleColor(ImGuiCol_Text, COLOR_TEXT_MUTED);
    }

    bool result = ImGui::BeginMenu(id);
    *wasHovered = ImGui::IsItemHovered(ImGuiHoveredFlags_RectOnly);
    return result;
}
