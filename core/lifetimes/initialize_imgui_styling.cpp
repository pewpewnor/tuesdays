#include "initialize_imgui_styling.hpp"

#include <imgui-SFML.h>
#include <imgui.h>

#include "globals/fonts.hpp"

void InitializeImguiStyling::onStartup() {
    ImGui::StyleColorsDark();

    ImGui::GetIO().FontDefault = g::fonts->sansRegular;

    ImGui::GetStyle().WindowBorderSize = 0;
}
