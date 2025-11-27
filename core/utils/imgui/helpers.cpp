#include "helpers.hpp"

#include <imgui.h>

bool nextWidgetIsHovered(float widgetWidth, float widgetHeight) {
    ImVec2 nextWidgetPos = ImGui::GetCursorScreenPos();
    return ImGui::IsMouseHoveringRect(
        nextWidgetPos, {nextWidgetPos.x + widgetWidth, nextWidgetPos.y + widgetHeight});
}
