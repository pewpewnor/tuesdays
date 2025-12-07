#include "iws_server_group_dropdown.hpp"

#include <imgui-SFML.h>

#include "globals/engine_state.hpp"
#include "imgui.h"
#include "utils/imgui/child_window_flags_builder.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

IwsServerGroupDropdown::IwsServerGroupDropdown(const std::string& serverGroupName)
    : serverGroupName_(serverGroupName) {}

bool IwsServerGroupDropdown::beginChildWindow() {
    ImGuiWindowFlags windowFlags = WindowFlagsBuilder().addStatic().build();

    StylesScoped windowStyles;
    windowStyles.pushStyleColor(ImGuiCol_ChildBg, wasHovered_ ? COLOR_CHOCOLATE : COLOR_NIGHT_2);

    ImGuiChildFlags childFlags =
        ChildWindowFlagsBuilder().addAutoResizeY().addAlwaysUseWindowPadding().build();

    return ImGui::BeginChild(("IwsServerGroupDropdown_" + serverGroupName_).c_str(), {0, 0},
                             childFlags, windowFlags);
}

void IwsServerGroupDropdown::displayChildWindowContent() {
    ImGui::Dummy({0, 16});

    ImGui::TextUnformatted(serverGroupName_.c_str());

    bool isHovered = ImGui::IsWindowHovered();
    if (isHovered && !wasHovered_) {
        g::engine->sendRefreshSignal();
    }
    wasHovered_ = isHovered;
}
