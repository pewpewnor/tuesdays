#include "default_imgui_styling.hpp"

#include <imgui-SFML.h>
#include <imgui.h>

#include "globals/fonts.hpp"

void DefaultImguiStyling::onStartup() {
    ImGui::StyleColorsDark();

    ImGui::GetIO().FontDefault = g::fonts->sansRegular;

    ImGui::GetStyle().WindowBorderSize = 0;
    ImGui::GetStyle().WindowPadding = {0, 0};
    ImGui::GetStyle().ItemSpacing = {0, 0};
}
