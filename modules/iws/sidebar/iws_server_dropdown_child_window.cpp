#include "iws_server_dropdown_child_window.hpp"

#include <imgui-SFML.h>

#include "globals/engine_state.hpp"
#include "globals/textures.hpp"
#include "imgui.h"
#include "utils/imgui/child_window_flags_builder.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/helpers.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

IwsServerDropdownChildWindow::IwsServerDropdownChildWindow(
    const std::shared_ptr<iws::Server>& server)
    : server_(server) {}

bool IwsServerDropdownChildWindow::begin() {
    ImGuiWindowFlags windowFlags = WindowFlagsBuilder().addStatic().build();

    StylesScoped windowStyles;
    windowStyles.pushStyleVarY(ImGuiStyleVar_WindowPadding, 12);
    windowStyles.pushStyleColor(ImGuiCol_ChildBg, wasHovered_ ? COLOR_CHOCOLATE : COLOR_NIGHT_2);

    ImGuiChildFlags childFlags =
        ChildWindowFlagsBuilder().addAutoResizeY().addAlwaysUseWindowPadding().build();

    return ImGui::BeginChild(("IwsServerDropdownChildWindow_" + server_->name).c_str(), {0, 0},
                             childFlags, windowFlags);
}

void IwsServerDropdownChildWindow::renderContent() {
    ImGui::Dummy({16, 0});

    ImGui::SameLine();

    ImGui::Image(isOpen_ ? g::textures->chevronDownIconGray : g::textures->chevronRightIconGray,
                 {16, 16});

    ImGui::SameLine();

    ImGui::Dummy({8, 0});

    ImGui::SameLine();

    ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 3);  // subtract for small align adjustments
    ImGui::TextUnformatted(server_->name.c_str());

    ImGui::SameLine();

    auto endpointsCountStr = std::to_string(server_->endpoints.size());
    const char* endpointsCountCStr = endpointsCountStr.c_str();
    constexpr float windowRightPadding = 16;
    putNexItemAtTheEndOfWindow(ImGui::CalcTextSize(endpointsCountCStr).x, windowRightPadding);
    ImGui::TextUnformatted(endpointsCountCStr);

    bool isHovered = ImGui::IsWindowHovered();
    if (isHovered && !wasHovered_) {
        g::engine->sendRefreshSignal();
    }
    wasHovered_ = isHovered;
}
