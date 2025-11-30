#include "navbar.hpp"

#include <imgui-SFML.h>

#include "commons/components.hpp"
#include "globals/textures.hpp"
#include "universal/states/current_app.hpp"
#include "universal/states/universal_state.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

bool Navbar::beginWindow() {
    ImGui::SetNextWindowPos({0, 0});
    ImGui::SetNextWindowSize({0, ImGui::GetMainViewport()->WorkSize.y}, ImGuiCond_Always);
    ImGuiWindowFlags windowFlags = WindowFlagsBuilder().addStatic().build();

    StylesScoped windowStyles;
    windowStyles.pushStyleVar(ImGuiStyleVar_WindowPadding, {12, 12});
    windowStyles.pushStyleColor(ImGuiCol_WindowBg, COLOR_NIGHT_1);

    return ImGui::Begin("Navbar", nullptr, windowFlags);
}

void Navbar::renderWindowContent() {
    {
        StylesScoped appIconsStyles;
        appIconsStyles.pushStyleVarY(ImGuiStyleVar_ItemSpacing, 18);

        if (components::navbarAppImageButton("Navbar_AcmAppIcon", univ::currentAppIsAcm(),
                                             g::textures->lightningBoltIconWhite)) {
            univ::state->currentApp = univ::CurrentApp::Acm;
        }
        if (components::navbarAppImageButton("Navbar_IsAppIcon", univ::currentAppIsIws(),
                                             g::textures->signalTowerIconWhite)) {
            univ::state->currentApp = univ::CurrentApp::Iws;
        }
    }
}
