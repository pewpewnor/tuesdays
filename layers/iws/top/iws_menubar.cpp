#include "iws_menubar.hpp"

#include <imgui.h>

#include "globals/fonts.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/font_scoped.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

IwsMenubar::IwsMenubar(const std::shared_ptr<Topbar>& topbar) : topbar_(topbar) {}

bool IwsMenubar::beginWindow() {
    ImGui::SetNextWindowPos({topbar_->windowPos.x, topbar_->windowPos.y + 4});
    ImGui::SetNextWindowSize({0, topbar_->windowSize.y - 16});

    ImGuiWindowFlags windowFlag = WindowFlagsBuilder().addMenuBar().addStatic().build();

    StylesScoped windowStyles;
    windowStyles.pushStyleVar(ImGuiStyleVar_WindowMinSize, {0, 0});  // remove bottom margin
    windowStyles.pushStyleVar(ImGuiStyleVar_WindowPadding, {16, 4});
    windowStyles.pushStyleColor(ImGuiCol_MenuBarBg, COLOR_NIGHT_1);

    return ImGui::Begin("IwsMenubar", nullptr, windowFlag);
}

void IwsMenubar::renderWindowContent() {
    StylesScoped menuBarStyles;
    menuBarStyles.pushStyleVar(ImGuiStyleVar_PopupRounding, 4);
    menuBarStyles.pushStyleVar(ImGuiStyleVar_ItemSpacing, {10, 4});  // menu padding

    if (ImGui::BeginMenuBar()) {
        ImGui::AlignTextToFramePadding();
        {
            StylesScoped appTitleStyles;
            FontScoped font(g::fonts->sansBold.get());
            ImGui::TextUnformatted("WEB-SERVER");
        }

        ImGui::Dummy(ImVec2(12, 0));

        StylesScoped menuItemsStyles;
        menuItemsStyles.pushStyleVar(ImGuiStyleVar_WindowPadding, {18, 22});
        menuItemsStyles.pushStyleVarY(ImGuiStyleVar_ItemSpacing, 16);
        menuItemsStyles.pushStyleColor(ImGuiCol_PopupBg, COLOR_NIGHT_4);
        menuItemsStyles.pushStyleColor(ImGuiCol_Text, COLOR_FG_MUTED);
        menuItemsStyles.pushStyleColor(ImGuiCol_HeaderHovered, COLOR_CHOCOLATE);
        menuItemsStyles.pushStyleColor(ImGuiCol_HeaderActive, COLOR_CHOCOLATE);
        menuItemsStyles.pushStyleColor(ImGuiCol_Header, COLOR_TRANSPARENT);

        fileMenu_.display();
        editMenu_.display();
        viewMenu_.display();

        ImGui::EndMenuBar();
    }
}
