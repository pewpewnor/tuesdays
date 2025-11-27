#include "image_buttons.hpp"

#include <imgui-SFML.h>

#include "imgui.h"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/helpers.hpp"
#include "utils/imgui/styles_scoped.hpp"

bool components::navbarAppImageButton(const char* id, bool isActive, const sf::Texture& on,
                                      const sf::Texture& off) {
    constexpr float size = 28;
    constexpr float padding = 8;
    constexpr float fullSideSize = size + (padding * 2);

    bool isHovered = nextWidgetIsHovered(fullSideSize, fullSideSize);

    StylesScoped styles;
    styles.pushStyleVar(ImGuiStyleVar_FrameRounding, 8);
    styles.pushStyleVar(ImGuiStyleVar_FramePadding, {padding, padding});
    styles.pushStyleColor(ImGuiCol_Button, isActive ? colorHex("#d56f2c") : COLOR_TRANSPARENT);
    styles.setHoverAndActiveColor(isActive ? colorHex("#c5682b") : colorHex("#5b382e"));

    return ImGui::ImageButton(id, (isActive || isHovered) ? on : off, {size, size});
}
