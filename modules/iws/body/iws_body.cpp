#include "iws_body.hpp"

#include <imgui.h>

#include "universal/states/current_app.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

IwsBody::IwsBody(const std::shared_ptr<Topbar>& topbar,
                 const std::shared_ptr<IwsSidebar>& acmSidebar)
    : topbar_(topbar), acmSidebar_(acmSidebar) {}

bool IwsBody::shouldRender() { return univ::currentAppIsIws(); }

bool IwsBody::beginWindow() {
    ImVec2 windowPos{acmSidebar_->windowPos.x + acmSidebar_->windowSize.x,
                     topbar_->windowPos.y + topbar_->windowSize.y};
    ImGui::SetNextWindowPos(windowPos);
    ImGui::SetNextWindowSize({ImGui::GetMainViewport()->WorkSize.x - windowPos.x,
                              ImGui::GetMainViewport()->WorkSize.y - windowPos.y});

    ImGuiWindowFlags windowFlags = WindowFlagsBuilder().addStatic().build();

    StylesScoped windowStyles;
    windowStyles.pushStyleVar(ImGuiStyleVar_WindowPadding, {8, 8});
    windowStyles.pushStyleColor(ImGuiCol_WindowBg, COLOR_NIGHT_3);

    return ImGui::Begin("IwsBody", nullptr, windowFlags);
}

void IwsBody::renderWindowContent() { ImGui::TextUnformatted("hey"); }
