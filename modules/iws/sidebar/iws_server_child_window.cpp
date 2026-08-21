#include "iws_server_child_window.hpp"

#include <imgui-SFML.h>

#include "iws/states/endpoint.hpp"
#include "iws/states/server.hpp"
#include "universal/components/image_buttons.hpp"
#include "utils/imgui/child_window_flags_builder.hpp"
#include "utils/imgui/helpers.hpp"
#include "utils/imgui/window_flags_builder.hpp"

IwsServerChildWindow::IwsServerChildWindow(const std::shared_ptr<iws::Server>& server)
    : serverLeftDropdownChildWindow_(server), server_(server) {
    for (const std::shared_ptr<iws::Endpoint>& endpoint : server_->endpoints) {
        endpointListChildWindow_.endpointChildWindows.emplace_back(endpoint);
    }
}

bool IwsServerChildWindow::begin() {
    ImGuiWindowFlags windowFlags = WindowFlagsBuilder().addStatic().build();
    ImGuiChildFlags childFlags = ChildWindowFlagsBuilder().addAutoResizeY().build();

    return ImGui::BeginChild(("IwsServerChildWindow_" + server_->name).c_str(), {0, 0}, childFlags,
                             windowFlags);
}

void IwsServerChildWindow::renderContent() {
    constexpr float windowRightPadding = 14;
    constexpr int additionalWindowRightPaddingAlignAdjustment = 2;
    constexpr float plusButtonSize = 16;
    constexpr float rightSideSize =
        ((windowRightPadding + additionalWindowRightPaddingAlignAdjustment) * 2) + plusButtonSize;

    serverLeftDropdownChildWindow_.windowSizeX = ImGui::GetWindowSize().x - rightSideSize;
    serverLeftDropdownChildWindow_.display();

    ImGui::SameLine();

    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 10);

    putNexItemAtTheEndOfWindow(plusButtonSize, windowRightPadding);
    if (components::plusIconButton("IwsServerChildWindow_Plus", 16)) {
    };

    if (serverLeftDropdownChildWindow_.isOpen) {
        endpointListChildWindow_.display();
    }
}
