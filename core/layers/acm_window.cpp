#include "acm_window.hpp"

#include "globals/universal.hpp"
#include "navbar.hpp"
#include "utils/imgui/window_flags_builder.hpp"

AcmWindow::AcmWindow(const std::shared_ptr<Navbar>& suiteSidebar) : suiteSidebar_(suiteSidebar) {}

bool AcmWindow::shouldRender() { return univ::state->currentApp == univ::CurrentApp::Acm; }

void AcmWindow::onRender() {
    ImGui::SetNextWindowPos({suiteSidebar_->windowPos.x + suiteSidebar_->windowSize.x, 0});
    ImGui::SetNextWindowSize({ImGui::GetMainViewport()->WorkSize.x - suiteSidebar_->windowSize.x,
                              ImGui::GetMainViewport()->WorkSize.y});
    ImGuiWindowFlags windowFlags =
        WindowFlagsBuilder().addPlain().addNoBringToFrontOnFocus().build();
    ImGui::Begin("AcmWindow", nullptr, windowFlags);

    ImGui::End();
}
