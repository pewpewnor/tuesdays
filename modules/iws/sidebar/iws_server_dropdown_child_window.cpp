#include "iws_server_dropdown_child_window.hpp"

#include <imgui-SFML.h>

#include "globals/engine_state.hpp"
#include "imgui.h"
#include "utils/imgui/child_window_flags_builder.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

IwsServerDropdownChildWindow::IwsServerDropdownChildWindow(const std::string& serverName)
    : serverName_(serverName) {}

bool IwsServerDropdownChildWindow::beginChildWindow() {
    ImGuiWindowFlags windowFlags = WindowFlagsBuilder().addStatic().build();

    StylesScoped windowStyles;
    windowStyles.pushStyleColor(ImGuiCol_ChildBg, wasHovered_ ? COLOR_CHOCOLATE : COLOR_NIGHT_2);

    ImGuiChildFlags childFlags =
        ChildWindowFlagsBuilder().addAutoResizeY().addAlwaysUseWindowPadding().build();

    return ImGui::BeginChild(("IwsServerDropdownChildWindow_" + serverName_).c_str(), {0, 0},
                             childFlags, windowFlags);
}

void IwsServerDropdownChildWindow::displayChildWindowContent() {
    ImGui::Dummy({0, 16});

    ImGui::TextUnformatted(serverName_.c_str());

    bool isHovered = ImGui::IsWindowHovered();
    if (isHovered && !wasHovered_) {
        g::engine->sendRefreshSignal();
    }
    wasHovered_ = isHovered;
}
