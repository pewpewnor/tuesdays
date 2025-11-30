#include "topbar.hpp"

#include <imgui.h>

#include "utils/imgui/colors.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

Topbar::Topbar(const std::shared_ptr<Navbar>& navbar) : navbar_(navbar) {}

bool Topbar::beginWindow() {
    ImGui::SetNextWindowPos({navbar_->windowPos.x + navbar_->windowSize.x, 0});
    ImGui::SetNextWindowSize({ImGui::GetMainViewport()->WorkSize.x - navbar_->windowSize.x, 34});

    ImGuiWindowFlags windowFlag = WindowFlagsBuilder().addNoInputs().addStatic().build();

    StylesScoped windowStyles;
    windowStyles.pushStyleColor(ImGuiCol_WindowBg, COLOR_NIGHT_1);

    return ImGui::Begin("Topbar", nullptr, windowFlag);
}

void Topbar::renderWindowContent() {}
