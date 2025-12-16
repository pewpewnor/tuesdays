#include "iws_body_window.hpp"

#include <imgui.h>

#include "utils/imgui/colors.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

IwsBodyWindow::IwsBodyWindow(const std::shared_ptr<TopbarWindow>& topbar,
                             const std::shared_ptr<IwsSidebarWindow>& iwsSidebarWindow)
    : topbar_(topbar), iwsSidebarWindow_(iwsSidebarWindow) {}

bool IwsBodyWindow::begin() {
    StylesScoped windowStyles;
    windowStyles.pushStyleVar(ImGuiStyleVar_WindowPadding, {8, 8});
    windowStyles.pushStyleColor(ImGuiCol_WindowBg, COLOR_NIGHT_3);

    ImVec2 windowPos{iwsSidebarWindow_->windowPos.x + iwsSidebarWindow_->windowSize.x,
                     topbar_->windowPos.y + topbar_->windowSize.y};
    ImGui::SetNextWindowPos(windowPos);
    ImGui::SetNextWindowSize({ImGui::GetMainViewport()->WorkSize.x - windowPos.x,
                              ImGui::GetMainViewport()->WorkSize.y - windowPos.y});

    ImGuiWindowFlags windowFlags =
        WindowFlagsBuilder().addNoBringToFrontOnFocus().addStatic().build();

    return ImGui::Begin("IwsBodyWindow", nullptr, windowFlags);
}

void IwsBodyWindow::renderContent() { ImGui::TextUnformatted("hey"); }
