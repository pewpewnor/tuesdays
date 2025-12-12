#include "topbar_window.hpp"

#include <imgui.h>

#include "utils/imgui/colors.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

TopbarWindow::TopbarWindow(const std::shared_ptr<NavbarWindow>& navbar) : navbar_(navbar) {}

bool TopbarWindow::beginWindow() {
    ImGui::SetNextWindowPos({navbar_->windowPos.x + navbar_->windowSize.x, 0});
    ImGui::SetNextWindowSize({ImGui::GetMainViewport()->WorkSize.x - navbar_->windowSize.x, 40});

    ImGuiWindowFlags windowFlag = WindowFlagsBuilder().addNoInputs().addStatic().build();

    StylesScoped windowStyles;
    windowStyles.pushStyleColor(ImGuiCol_WindowBg, COLOR_NIGHT_1);

    return ImGui::Begin("TopbarWindow", nullptr, windowFlag);
}

void TopbarWindow::renderWindowContent() {}
