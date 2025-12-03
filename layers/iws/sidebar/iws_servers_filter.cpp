#include "iws_servers_filter.hpp"

#include <imgui.h>

#include "components/image_buttons.hpp"
#include "globals/engine_state.hpp"
#include "globals/fonts.hpp"
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
    windowStyles.pushStyleVar(ImGuiStyleVar_WindowPadding, {16, 8});
    windowStyles.pushStyleColor(ImGuiCol_WindowBg, COLOR_NIGHT_2);

    return ImGui::Begin("IwsServersFilter", nullptr, windowFlags);
}

void IwsServersFilter::renderWindowContent() {
    ImGui::AlignTextToFramePadding();
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
        ImGui::OpenPopup("IwsModalCreateServer");
        g::engine->sendRefreshSignal(10);
    };

    createServerModal_.display();
}
