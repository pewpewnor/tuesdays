#include "iws_server_child_window.hpp"

#include <imgui-SFML.h>

#include "iws/states/server.hpp"
#include "utils/imgui/child_window_flags_builder.hpp"
#include "utils/imgui/window_flags_builder.hpp"

IwsServerChildWindow::IwsServerChildWindow(const std::shared_ptr<iws::Server>& server)
    : server(server), serverDropdownChildWindow_(server) {}

bool IwsServerChildWindow::beginChildWindow() {
    ImGuiWindowFlags windowFlags = WindowFlagsBuilder().addStatic().build();

    ImGuiChildFlags childFlags =
        ChildWindowFlagsBuilder().addAutoResizeY().addAlwaysUseWindowPadding().build();

    return ImGui::BeginChild(("IwsServerChildWindow_" + server->name).c_str(), {0, 0}, childFlags,
                             windowFlags);
}

void IwsServerChildWindow::displayChildWindowContent() { serverDropdownChildWindow_.display(); }
