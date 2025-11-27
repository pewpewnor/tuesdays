#pragma once

#include <imgui.h>

class StylesScoped {
public:
    StylesScoped() = default;
    StylesScoped(const StylesScoped&) = delete;
    StylesScoped(StylesScoped&&) = delete;
    StylesScoped& operator=(const StylesScoped&) = delete;
    StylesScoped& operator=(StylesScoped&&) = delete;

    ~StylesScoped();

    void pushStyleVar(ImGuiStyleVar styleVar, float value);

    void pushStyleVar(ImGuiStyleVar styleVar, const ImVec2& values);

    void pushStyleVarX(ImGuiStyleVar styleVar, float value);

    void pushStyleVarY(ImGuiStyleVar styleVar, float value);

    void pushStyleColor(ImGuiCol column, const ImVec4& color);

    void setHoverAndActiveColor(const ImVec4& color);

    void reset();

private:
    int varCount_ = 0;
    int colorCount_ = 0;

    void clear();
};
