#include "iws_sidebar_window.hpp"

#include <imgui-SFML.h>

#include "globals/engine_state.hpp"
#include "globals/fonts.hpp"
#include "globals/textures.hpp"
#include "imgui.h"
#include "iws/states/iws_state.hpp"
#include "universal/components/image_buttons.hpp"
#include "utils/assertions.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/font_scoped.hpp"
#include "utils/imgui/helpers.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

IwsSidebarWindow::IwsSidebarWindow(const std::shared_ptr<NavbarWindow>& navbarWindow,
                                   const std::shared_ptr<TopbarWindow>& topbarWindow)
    : navbarWindow_(navbarWindow), topbarWindow_(topbarWindow) {}

bool IwsSidebarWindow::begin() {
    ImGui::SetNextWindowPos({navbarWindow_->windowPos.x + navbarWindow_->windowSize.x,
                             topbarWindow_->windowPos.y + topbarWindow_->windowSize.y});
    ImGui::SetNextWindowSize(
        {300, ImGui::GetMainViewport()->WorkSize.y - topbarWindow_->windowSize.y});
    ImGuiWindowFlags windowFlags = WindowFlagsBuilder()
                                       .addNoBringToFrontOnFocus()
                                       .addNoMove()
                                       .addNoCollapse()
                                       .addNoDecoration()
                                       .build();

    StylesScoped windowStyles;
    windowStyles.pushStyleColor(ImGuiCol_WindowBg, COLOR_NIGHT_2);

    return ImGui::Begin("IwsSidebarWindow", nullptr, windowFlags);
}

void IwsSidebarWindow::renderContent() {
    ImGui::Dummy({0, 20});

    ImGui::Dummy({16, 0});

    ImGui::SameLine();

    ImGui::Image(g::textures->listIconGray, {20, 20});

    ImGui::SameLine();

    ImGui::Dummy({8, 0});

    ImGui::SameLine();

    {
        StylesScoped contentStyles;
        contentStyles.pushStyleColor(ImGuiCol_Text, COLOR_FG_MUTED);
        FontScoped font(g::fonts->sansBold.get());
        ImGui::TextUnformatted("SERVERS");
    }

    ImGui::SameLine();

    constexpr float plusButtonSize = 16;
    constexpr float windowRightPadding = 16;
    putNexItemAtTheEndOfWindow(plusButtonSize,
                               windowRightPadding + 2);  // add for small align adjustments
    if (components::plusIconButton("IwsSidebarWindow_PlusServer", 16)) {
        ASSERT(!iws::state->showCreateServerModal, "button cannot be pressed again");
        iws::state->showCreateServerModal = true;
        iwsCreateServerModal_ = std::make_unique<IwsCreateServerModalPart>();
        ImGui::OpenPopup("IwsCreateServerModal");
        g::engine->sendRefreshSignal(10);
    };

    ImGui::Dummy({0, 12});

    for (IwsServerChildWindow& serverGroupChildWindow : iws::state->serverChildWindows) {
        serverGroupChildWindow.display();
    }

    if (iws::state->showCreateServerModal) {
        ASSERT(iwsCreateServerModal_, "modal show state and existance must be in sync");
        iwsCreateServerModal_->display();
    } else {
        iwsCreateServerModal_.reset();
    }

    windowPos = ImGui::GetWindowPos();
    windowSize = ImGui::GetWindowSize();
}
