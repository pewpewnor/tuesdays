#include "default_imgui_styling.hpp"

#include <imgui-SFML.h>
#include <imgui.h>

#include "globals/fonts.hpp"
#include "utils/imgui/colors.hpp"

void DefaultImguiStyling::onStartup() {
    ImGui::StyleColorsDark();

    ImGui::GetIO().FontDefault = g::fonts->sansRegular;

    ImGui::GetStyle().WindowBorderSize = 0;
    ImGui::GetStyle().WindowPadding = {0, 0};
    ImGui::GetStyle().ItemSpacing = {0, 0};

    ImGui::GetStyle().Colors[ImGuiCol_Button] = COLOR_TRANSPARENT;
    ImGui::GetStyle().Colors[ImGuiCol_ButtonHovered] = COLOR_CHOCOLATE;
    ImGui::GetStyle().Colors[ImGuiCol_ButtonActive] = COLOR_TRANSPARENT;
}
