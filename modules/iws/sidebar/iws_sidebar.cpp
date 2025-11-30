#include "iws_sidebar.hpp"

#include <imgui.h>

#include "utils/imgui/colors.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

IwsSidebar::IwsSidebar(const std::shared_ptr<Navbar>& navbar, const std::shared_ptr<Topbar>& topbar)
    : navbar_(navbar), topbar_(topbar) {}

bool IwsSidebar::beginWindow() {
    ImGui::SetNextWindowPos({navbar_->windowPos.x + navbar_->windowSize.x,
                             topbar_->windowPos.y + topbar_->windowSize.y});
    ImGui::SetNextWindowSize({300, ImGui::GetMainViewport()->WorkSize.y - topbar_->windowSize.y});
    ImGuiWindowFlags windowFlags = WindowFlagsBuilder()
                                       .addNoBringToFrontOnFocus()
                                       .addNoMove()
                                       .addNoCollapse()
                                       .addNoDecoration()
                                       .build();

    StylesScoped windowStyles;
    windowStyles.pushStyleColor(ImGuiCol_WindowBg, COLOR_NIGHT_2);

    return ImGui::Begin("IwsSidebar", nullptr, windowFlags);
}
