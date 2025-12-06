#include "iws_server_groups.hpp"

#include <imgui.h>

#include "utils/imgui/colors.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

IwsServerGroups::IwsServerGroups(const std::shared_ptr<IwsServerGroupsFilter>& iwsServersFilter)
    : iwsServersFilter_(iwsServersFilter) {}

bool IwsServerGroups::beginWindow() {
    ImGui::SetNextWindowPos({iwsServersFilter_->windowPos.x,
                             iwsServersFilter_->windowPos.y + iwsServersFilter_->windowSize.y});
    ImGui::SetNextWindowSize({iwsServersFilter_->windowSize.x, 0});

    ImGuiWindowFlags windowFlags = WindowFlagsBuilder().addAlwaysAutoResize().addStatic().build();

    StylesScoped windowStyles;
    windowStyles.pushStyleVar(ImGuiStyleVar_WindowPadding, {16, 16});
    windowStyles.pushStyleColor(ImGuiCol_WindowBg, COLOR_NIGHT_2);

    return ImGui::Begin("IwsServersList", nullptr, windowFlags);
}

void IwsServerGroups::renderWindowContent() { ImGui::TextUnformatted("hey"); }
