#include "navbar.hpp"

#include <imgui-SFML.h>
#include <imgui.h>

#include "components/image_buttons.hpp"
#include "globals/textures.hpp"
#include "globals/universal.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

void Navbar::onRender() {
    ImGui::SetNextWindowPos({0, 0});
    ImGui::SetNextWindowSize({0, ImGui::GetMainViewport()->WorkSize.y}, ImGuiCond_Always);
    ImGuiWindowFlags windowFlags = WindowFlagsBuilder().addPlain().build();
    {
        StylesScoped styles;
        styles.pushStyleVar(ImGuiStyleVar_WindowPadding, {14, 14});
        styles.pushStyleColor(ImGuiCol_WindowBg, colorHex("#332820"));

        ImGui::Begin("Navbar", nullptr, windowFlags);
    }

    {
        StylesScoped styles;
        styles.pushStyleVarY(ImGuiStyleVar_ItemSpacing, 18);

        if (components::navbarAppImageButton(
                "AcmAppIcon", univ::state->currentApp == univ::CurrentApp::Acm,
                g::textures->lightningBoltIconBlack, g::textures->lightningBoltIconWhite)) {
            univ::state->currentApp = univ::CurrentApp::Acm;
        }
    }
    if (components::navbarAppImageButton(
            "IsAppIcon", univ::state->currentApp == univ::CurrentApp::Is,
            g::textures->radarIconBlack, g::textures->radarIconWhite)) {
        univ::state->currentApp = univ::CurrentApp::Is;
    }

    windowPos = ImGui::GetWindowPos();
    windowSize = ImGui::GetWindowSize();

    ImGui::End();
}
