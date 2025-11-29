#include "helpers.hpp"

#include <imgui.h>

bool nextWidgetIsHovered(float widgetWidth, float widgetHeight) {
    ImVec2 nextWidgetPos = ImGui::GetCursorScreenPos();
    return ImGui::IsMouseHoveringRect(
        nextWidgetPos, {nextWidgetPos.x + widgetWidth, nextWidgetPos.y + widgetHeight});
}

void putNexItemAtTheEndOfWindow(float itemWidth, float gap) {
    float windowWidth = ImGui::GetWindowContentRegionMax().x;
    float currentPosX = ImGui::GetCursorPosX();
    float targetPosX = windowWidth - itemWidth - gap - ImGui::GetStyle().ItemSpacing.x -
                       (ImGui::GetStyle().FramePadding.x * 2);
    if (targetPosX > currentPosX) {
        ImGui::SetCursorPosX(targetPosX);
    }
}
