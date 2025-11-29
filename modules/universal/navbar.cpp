#include "navbar.hpp"

#include <imgui-SFML.h>

#include "components/components.hpp"
#include "globals/textures.hpp"
#include "universal/states/universal_state.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

bool Navbar::beginWindow() {
    ImGui::SetNextWindowPos({0, 0});
    ImGui::SetNextWindowSize({0, ImGui::GetMainViewport()->WorkSize.y}, ImGuiCond_Always);
    ImGuiWindowFlags windowFlags = WindowFlagsBuilder().addStatic().build();

    StylesScoped windowStyle;
    windowStyle.pushStyleVar(ImGuiStyleVar_WindowPadding, {12, 12});
    windowStyle.pushStyleColor(ImGuiCol_WindowBg, COLOR_NIGHT_1);

    return ImGui::Begin("Navbar", nullptr, windowFlags);
}

void Navbar::renderWindowContent() {
    {
        StylesScoped appIconsStyle;
        appIconsStyle.pushStyleVarY(ImGuiStyleVar_ItemSpacing, 18);

        if (components::navbarAppImageButton(
                "Navbar_AcmAppIcon", univ::state->currentApp == univ::CurrentApp::Acm,
                g::textures->lightningBoltIconWhite, g::textures->lightningBoltIconBlack)) {
            univ::state->currentApp = univ::CurrentApp::Acm;
        }
        if (components::navbarAppImageButton(
                "Navbar_IsAppIcon", univ::state->currentApp == univ::CurrentApp::Is,
                g::textures->signalTowerIconWhite, g::textures->signalTowerIconBlack)) {
            univ::state->currentApp = univ::CurrentApp::Is;
        }
    }
}
