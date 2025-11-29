#include "acm_body.hpp"

#include <imgui.h>

#include "acm_sidebar.hpp"
#include "universal/states/universal_state.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

AcmBody::AcmBody(const std::shared_ptr<Topbar>& topbar,
                 const std::shared_ptr<AcmSidebar>& acmSidebar)
    : topbar_(topbar), acmSidebar_(acmSidebar) {}

bool AcmBody::shouldRender() { return univ::state->currentApp == univ::CurrentApp::Acm; }

bool AcmBody::beginWindow() {
    ImVec2 windowPos{acmSidebar_->windowPos.x + acmSidebar_->windowSize.x,
                     topbar_->windowPos.y + topbar_->windowSize.y};
    ImGui::SetNextWindowPos(windowPos);
    ImGui::SetNextWindowSize({ImGui::GetMainViewport()->WorkSize.x - windowPos.x,
                              ImGui::GetMainViewport()->WorkSize.y - windowPos.y});

    ImGuiWindowFlags windowFlags = WindowFlagsBuilder().addStatic().build();

    StylesScoped windowStyles;
    windowStyles.pushStyleVar(ImGuiStyleVar_WindowPadding, {8, 8});
    windowStyles.pushStyleColor(ImGuiCol_WindowBg, COLOR_NIGHT_3);

    return ImGui::Begin("AcmBody", nullptr, windowFlags);
}

void AcmBody::renderWindowContent() { ImGui::TextUnformatted("hey"); }
