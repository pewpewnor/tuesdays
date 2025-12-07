#include "iws_server_group.hpp"

#include <imgui-SFML.h>

#include "iws/sidebar/iws_server_group_dropdown.hpp"
#include "iws/states/server_group.hpp"
#include "utils/imgui/child_window_flags_builder.hpp"
#include "utils/imgui/window_flags_builder.hpp"

IwsServerGroup::IwsServerGroup(const std::shared_ptr<iws::ServerGroup>& serverGroup)
    : serverGroup(serverGroup), serverGroupDropdown_(serverGroup->name) {}

bool IwsServerGroup::beginChildWindow() {
    ImGuiWindowFlags windowFlags = WindowFlagsBuilder().addStatic().build();

    ImGuiChildFlags childFlags =
        ChildWindowFlagsBuilder().addAutoResizeY().addAlwaysUseWindowPadding().build();

    return ImGui::BeginChild(("IwsServerGroup_" + serverGroup->name).c_str(), {0, 0}, childFlags,
                             windowFlags);
}

void IwsServerGroup::displayChildWindowContent() { serverGroupDropdown_.display(); }
