#include "iws_server_left_dropdown_child_window.hpp"

#include <imgui-SFML.h>

#include "globals/engine_state.hpp"
#include "globals/textures.hpp"
#include "utils/imgui/child_window_flags_builder.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/helpers.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

IwsServerLeftDropdownChildWindow::IwsServerLeftDropdownChildWindow(
    const std::shared_ptr<iws::Server>& server)
    : server_(server) {}

bool IwsServerLeftDropdownChildWindow::begin() {
    StylesScoped windowStyles;
    windowStyles.pushStyleVarY(ImGuiStyleVar_WindowPadding, 12);
    windowStyles.pushStyleColor(ImGuiCol_ChildBg, wasHovered_ ? COLOR_CHOCOLATE : COLOR_NIGHT_2);

    ImGui::SetNextWindowSize({windowSizeX, 0});

    ImGuiWindowFlags windowFlags = WindowFlagsBuilder().addStatic().build();
    ImGuiChildFlags childFlags =
        ChildWindowFlagsBuilder().addAutoResizeY().addAlwaysUseWindowPadding().build();

    return ImGui::BeginChild(("IwsServerDropdownChildWindow_" + server_->name).c_str(), {0, 0},
                             childFlags, windowFlags);
}

void IwsServerLeftDropdownChildWindow::renderContent() {
    ImGui::Dummy({16, 0});

    ImGui::SameLine();

    ImGui::Image(isOpen ? g::textures->chevronDownIconGray : g::textures->chevronRightIconGray,
                 {16, 16});

    ImGui::SameLine();

    ImGui::Dummy({8, 0});

    ImGui::SameLine();

    constexpr int serverNameStartYAlignAdjustment = 2;
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() - serverNameStartYAlignAdjustment);
    ImGui::TextUnformatted(server_->name.c_str());

    ImGui::SameLine();

    {
        StylesScoped endpointsCountStyles;
        endpointsCountStyles.pushStyleColor(ImGuiCol_Text, COLOR_FG_MUTED);

        auto endpointsCountStr = std::to_string(server_->endpoints.size());
        const char* endpointsCountCStr = endpointsCountStr.c_str();
        constexpr float windowRightPadding = 4;
        putNexItemAtTheEndOfWindow(ImGui::CalcTextSize(endpointsCountCStr).x, windowRightPadding);
        ImGui::TextUnformatted(endpointsCountCStr);
    }

    if (isWindowLeftClicked()) {
        isOpen = !isOpen;
        g::engine->sendRefreshSignal();  // for auto resize
    }

    wasHovered_ = ImGui::IsWindowHovered();
}
