#include "image_buttons.hpp"

#include <imgui-SFML.h>

#include "SFML/Graphics/Texture.hpp"
#include "globals/textures.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/helpers.hpp"
#include "utils/imgui/styles_scoped.hpp"

namespace {

bool actionIconButton(const std::string& label, float size, const sf::Texture& notHovered,
                      const sf::Texture& hovered) {
    bool isHovered = nextItemIsHovered(size + 8, size + 8);
    StylesScoped plusButtonStyles;
    plusButtonStyles.pushStyleVar(ImGuiStyleVar_FrameRounding, 16);

    return ImGui::ImageButton(label.c_str(), isHovered ? hovered : notHovered, {size, size});
}

}

bool components::navbarAppImageButton(const std::string& label, bool isActive,
                                      const sf::Texture& icon) {
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
    styles.pushStyleColor(ImGuiCol_Border, isActive ? COLOR_AZURE_SHADOW : COLOR_DARK_GREY);

    return ImGui::ImageButton(label.c_str(), icon, {size, size});
}

bool components::crossIconButton(const std::string& label, float size) {
    return actionIconButton(label, size, g::textures->crossIconMuted, g::textures->crossIconWhite);
}

bool components::plusIconButton(const std::string& label, float size) {
    return actionIconButton(label, size, g::textures->plusIconMuted, g::textures->plusIconWhite);
}
