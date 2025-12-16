#include "iws_menubar_window.hpp"

#include <imgui.h>

#include "globals/fonts.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/font_scoped.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

IwsMenubarWindow::IwsMenubarWindow(const std::shared_ptr<TopbarWindow>& topbarWindow)
    : topbarWindow_(topbarWindow) {}

bool IwsMenubarWindow::begin() {
    StylesScoped windowStyles;
    windowStyles.pushStyleVar(ImGuiStyleVar_WindowMinSize, {0, 0});  // remove bottom margin
    windowStyles.pushStyleVar(ImGuiStyleVar_WindowPadding, {16, 4});
    windowStyles.pushStyleColor(ImGuiCol_MenuBarBg, COLOR_NIGHT_1);

    ImGui::SetNextWindowPos({topbarWindow_->windowPos.x, topbarWindow_->windowPos.y + 8});
    ImGui::SetNextWindowSize({0, topbarWindow_->windowSize.y - 8});

    ImGuiWindowFlags windowFlag = WindowFlagsBuilder().addMenuBar().addStatic().build();

    return ImGui::Begin("IwsMenubarWindow", nullptr, windowFlag);
}

void IwsMenubarWindow::renderContent() {
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

        fileMenuPart_.display();
        editMenuPart_.display();
        viewMenuPart_.display();

        ImGui::EndMenuBar();
    }
}
