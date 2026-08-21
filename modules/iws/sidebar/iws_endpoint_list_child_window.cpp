#include "iws_endpoint_list_child_window.hpp"

#include "iws_endpoint_child_window.hpp"
#include "utils/imgui/child_window_flags_builder.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

bool IwsEndpointListChildWindow::begin() {
    StylesScoped windowStyles;
    windowStyles.pushStyleVar(ImGuiStyleVar_WindowPadding, {8, 8});

    ImGuiWindowFlags windowFlags = WindowFlagsBuilder().addStatic().build();
    ImGuiChildFlags childFlags =
        ChildWindowFlagsBuilder().addAutoResizeY().addAlwaysUseWindowPadding().build();

    return ImGui::BeginChild("IwsEndpointListChildWindow", {0, 0}, childFlags, windowFlags);
}

void IwsEndpointListChildWindow::renderContent() {
    for (IwsEndpointChildWindow& endpointChildWindow : endpointChildWindows) {
        endpointChildWindow.display();
    }
}
