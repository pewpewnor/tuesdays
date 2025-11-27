#include "styles_scoped.hpp"

#include <imgui.h>

void StylesScoped::pushStyleVar(ImGuiStyleVar styleVar, float value) {
    ImGui::PushStyleVar(styleVar, value);
    varCount_++;
}

void StylesScoped::pushStyleVar(ImGuiStyleVar styleVar, const ImVec2& values) {
    ImGui::PushStyleVar(styleVar, values);
    varCount_++;
}

void StylesScoped::pushStyleVarX(ImGuiStyleVar styleVar, float value) {
    ImGui::PushStyleVarX(styleVar, value);
    varCount_++;
}

void StylesScoped::pushStyleVarY(ImGuiStyleVar styleVar, float value) {
    ImGui::PushStyleVarY(styleVar, value);
    varCount_++;
}

void StylesScoped::pushStyleColor(ImGuiCol column, const ImVec4& color) {
    ImGui::PushStyleColor(column, color);
    colorCount_++;
}

void StylesScoped::setHoverAndActiveColor(const ImVec4& color) {
    pushStyleColor(ImGuiCol_ButtonHovered, color);
    pushStyleColor(ImGuiCol_ButtonActive, color);
}

void StylesScoped::reset() {
    clear();
    varCount_ = 0;
    colorCount_ = 0;
}

StylesScoped::~StylesScoped() { clear(); }

void StylesScoped::clear() {
    if (varCount_ > 0) {
        ImGui::PopStyleVar(varCount_);
    }
    if (colorCount_ > 0) {
        ImGui::PopStyleColor(colorCount_);
    }
}
