#include "iws_servers_filter.hpp"

#include <imgui-SFML.h>

#include "components/image_buttons.hpp"
#include "globals/engine_state.hpp"
#include "globals/fonts.hpp"
#include "globals/textures.hpp"
#include "imgui.h"
#include "iws/modals/iws_create_server_modal.hpp"
#include "iws/states/iws_state.hpp"
#include "utils/assertions.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/font_scoped.hpp"
#include "utils/imgui/helpers.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

IwsServersFilter::IwsServersFilter(const std::shared_ptr<IwsSidebar>& iwsSidebar)
    : iwsSidebar_(iwsSidebar) {}

bool IwsServersFilter::beginWindow() {
    ImGui::SetNextWindowPos(iwsSidebar_->windowPos);

    ImGui::SetNextWindowSize({iwsSidebar_->windowSize.x, 0});
    ImGuiWindowFlags windowFlags = WindowFlagsBuilder().addStatic().build();

    StylesScoped windowStyles;
    windowStyles.pushStyleVar(ImGuiStyleVar_WindowPadding, {16, 16});
    windowStyles.pushStyleColor(ImGuiCol_WindowBg, COLOR_NIGHT_2);

    return ImGui::Begin("IwsServersFilter", nullptr, windowFlags);
}

void IwsServersFilter::renderWindowContent() {
    ImGui::Image(g::textures->listIconMuted, {20, 20});

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
    if (components::plusIconButton("IwsServersFilter_PlusServer", 16)) {
        ASSERT(!iws::state->showCreateSeverModal, "button cannot be pressed again");
        iws::state->showCreateSeverModal = true;
        createServerModal_ = std::make_unique<IwsCreateServerModal>();
        ImGui::OpenPopup("IwsModalCreateServer");
        g::engine->sendRefreshSignal(10);
    };

    if (iws::state->showCreateSeverModal) {
        ASSERT(createServerModal_, "modal show state and existance must be in sync");
        createServerModal_->display();
    } else {
        createServerModal_.reset();
    }
}
