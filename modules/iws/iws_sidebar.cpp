#include "iws_sidebar.hpp"

#include <imgui.h>

#include "universal/states/universal_state.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

IwsSidebar::IwsSidebar(const std::shared_ptr<Navbar>& navbar, const std::shared_ptr<Topbar>& topbar)
    : navbar_(navbar), topbar_(topbar) {}

bool IwsSidebar::shouldRender() { return univ::state->currentApp == univ::CurrentApp::Iws; }

bool IwsSidebar::beginWindow() {
    ImGui::SetNextWindowPos({navbar_->windowPos.x + navbar_->windowSize.x,
                             topbar_->windowPos.y + topbar_->windowSize.y});
    ImGui::SetNextWindowSize({300, ImGui::GetMainViewport()->WorkSize.y - topbar_->windowSize.y});
    ImGuiWindowFlags windowFlags =
        WindowFlagsBuilder().addNoMove().addNoCollapse().addNoDecoration().build();

    StylesScoped windowStyle;
    windowStyle.pushStyleColor(ImGuiCol_WindowBg, COLOR_NIGHT_2);

    return ImGui::Begin("IwsSidebar", nullptr, windowFlags);
}

void IwsSidebar::renderWindowContent() {
    ImGui::TextUnformatted("Customize your settings in the settings.json file");
    ImGui::TextUnformatted(
        "Adipisci quisquam labore velit porro neque adipisci dolor. Sit dolorem porro "
        "neque ");
    ImGui::TextUnformatted(
        "dolorem dolorem neque. Consectetur etincidunt dolor dolore labore quisquam. "
        "est "
        "tempora sed.");
}
