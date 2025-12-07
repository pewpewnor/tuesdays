#include "iws_sidebar.hpp"

#include <imgui-SFML.h>

#include "globals/engine_state.hpp"
#include "globals/fonts.hpp"
#include "globals/textures.hpp"
#include "iws/sidebar/iws_server_group.hpp"
#include "iws/states/iws_state.hpp"
#include "iws/states/iws_ui.hpp"
#include "universal/components/image_buttons.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/font_scoped.hpp"
#include "utils/imgui/helpers.hpp"
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
    windowStyles.pushStyleVarX(ImGuiStyleVar_WindowPadding, 16);
    windowStyles.pushStyleColor(ImGuiCol_WindowBg, COLOR_NIGHT_2);

    return ImGui::Begin("IwsSidebar", nullptr, windowFlags);
}

void IwsSidebar::renderWindowContent() {
    ImGui::Dummy({0, 16});

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
    putNexItemAtTheEndOfWindow(plusButtonSize);
    if (components::plusIconButton("IwsSidebar_PlusServer", 16)) {
        ASSERT(!iws::state->showCreateServerModal, "button cannot be pressed again");
        iws::state->showCreateServerModal = true;
        iwsCreateServerGroupModal_ = std::make_unique<IwsCreateServerGroupModal>();
        ImGui::OpenPopup("IwsModalCreateServerGroup");
        g::engine->sendRefreshSignal(10);
    };

    if (iws::state->showCreateServerModal) {
        ASSERT(iwsCreateServerGroupModal_, "modal show state and existance must be in sync");
        iwsCreateServerGroupModal_->display();
    } else {
        iwsCreateServerGroupModal_.reset();
    }

    ImGui::Dummy({0, 8});

    for (const std::unique_ptr<IwsServerGroup>& serverGroupChildWindow :
         iws::ui->serverGroupChildWindows) {
        serverGroupChildWindow->display();
    }
}
