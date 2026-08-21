#include "iws_endpoint_child_window.hpp"

#include "iws/states/endpoint.hpp"
#include "utils/imgui/child_window_flags_builder.hpp"
#include "utils/imgui/window_flags_builder.hpp"

IwsEndpointChildWindow::IwsEndpointChildWindow(const std::shared_ptr<iws::Endpoint>& endpoint)
    : endpoint_(endpoint) {}

bool IwsEndpointChildWindow::begin() {
    ImGuiWindowFlags windowFlags = WindowFlagsBuilder().addStatic().build();
    ImGuiChildFlags childFlags = ChildWindowFlagsBuilder().addAutoResizeY().build();

    return ImGui::BeginChild(("IwsEndpointChildWindow_" + endpoint_->name).c_str(), {0, 0},
                             childFlags, windowFlags);
}

void IwsEndpointChildWindow::renderContent() { ImGui::TextUnformatted(endpoint_->name.c_str()); }
