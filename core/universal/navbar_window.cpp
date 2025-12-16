#include "navbar_window.hpp"

#include <imgui-SFML.h>

#include "components/image_buttons.hpp"
#include "globals/textures.hpp"
#include "universal/states/current_app.hpp"
#include "universal/states/universal_state.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

bool NavbarWindow::begin() {
    StylesScoped windowStyles;
    windowStyles.pushStyleVar(ImGuiStyleVar_WindowPadding, {12, 12});
    windowStyles.pushStyleColor(ImGuiCol_WindowBg, COLOR_NIGHT_1);

    ImGui::SetNextWindowPos({0, 0});
    ImGui::SetNextWindowSize({0, ImGui::GetMainViewport()->WorkSize.y}, ImGuiCond_Always);
    ImGuiWindowFlags windowFlags = WindowFlagsBuilder().addStatic().build();

    return ImGui::Begin("NavbarWindow", nullptr, windowFlags);
}

void NavbarWindow::renderContent() {
    {
        StylesScoped appIconsStyles;
        appIconsStyles.pushStyleVarY(ImGuiStyleVar_ItemSpacing, 18);

        if (components::navbarAppImageButton("NavbarWindow_AcmAppIcon",
                                             univ::state->currentApp == univ::CurrentApp::Acm,
                                             g::textures->lightningBoltIconWhite)) {
            univ::state->currentApp = univ::CurrentApp::Acm;
        }
        if (components::navbarAppImageButton("NavbarWindow_IsAppIcon",
                                             univ::state->currentApp == univ::CurrentApp::Iws,
                                             g::textures->signalTowerIconWhite)) {
            univ::state->currentApp = univ::CurrentApp::Iws;
        }
    }

    windowPos = ImGui::GetWindowPos();
    windowSize = ImGui::GetWindowSize();
}
