#include "acm_menubar.hpp"

#include <imgui.h>

#include "components/components.hpp"
#include "globals/fonts.hpp"
#include "universal/states/universal_state.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/font_scoped.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

AcmMenubar::AcmMenubar(const std::shared_ptr<Topbar>& topbar) : topbar_(topbar) {}

bool AcmMenubar::shouldRender() { return univ::state->currentApp == univ::CurrentApp::Acm; }

bool AcmMenubar::beginWindow() {
    ImGui::SetNextWindowPos({topbar_->windowPos.x, topbar_->windowPos.y + 4});
    ImGui::SetNextWindowSize({0, topbar_->windowSize.y - 16});

    ImGuiWindowFlags windowFlag = WindowFlagsBuilder().addMenuBar().addStatic().build();

    StylesScoped windowStyles;
    windowStyles.pushStyleVar(ImGuiStyleVar_WindowMinSize, {0, 0});  // remove bottom margin
    windowStyles.pushStyleVar(ImGuiStyleVar_WindowPadding, {24, 4});
    windowStyles.pushStyleColor(ImGuiCol_MenuBarBg, COLOR_NIGHT_1);

    return ImGui::Begin("AcmMenubar", nullptr, windowFlag);
}

void AcmMenubar::renderWindowContent() {
    bringWindowToFrontOnce_.checkForCurrentWindow();

    StylesScoped menuBarStyle;
    menuBarStyle.pushStyleVar(ImGuiStyleVar_PopupRounding, 4);
    menuBarStyle.pushStyleVar(ImGuiStyleVar_ItemSpacing, {10, 4});  // menu padding

    if (ImGui::BeginMenuBar()) {
        ImGui::AlignTextToFramePadding();
        {
            StylesScoped appTitleStyle;
            appTitleStyle.pushStyleColor(ImGuiCol_Text, COLOR_TEXT_FG);
            {
                FontScoped font(g::fonts->sansBold);
                ImGui::TextUnformatted("API-CLIENT");
            }
        }

        ImGui::Dummy(ImVec2(16, 0));

        StylesScoped menuItemsStyle;
        menuItemsStyle.pushStyleVar(ImGuiStyleVar_WindowPadding, {18, 22});
        menuItemsStyle.pushStyleVarY(ImGuiStyleVar_ItemSpacing, 16);
        menuItemsStyle.pushStyleColor(ImGuiCol_PopupBg, COLOR_NIGHT_4);
        menuItemsStyle.pushStyleColor(ImGuiCol_Text, COLOR_TEXT_MUTED);
        menuItemsStyle.pushStyleColor(ImGuiCol_HeaderHovered, COLOR_CHOCOLATE);
        menuItemsStyle.pushStyleColor(ImGuiCol_HeaderActive, COLOR_CHOCOLATE);
        menuItemsStyle.pushStyleColor(ImGuiCol_Header, COLOR_TRANSPARENT);

        if (components::beginMenubarMenu("File##AcmMenubar_File")) {
            renderFileMenu();
            ImGui::EndMenu();
        }

        ImGui::Dummy({4, 0});

        if (components::beginMenubarMenu("Edit##AcmMenubar_Edit")) {
            renderEditMenu();
            ImGui::EndMenu();
        }

        ImGui::Dummy({4, 0});

        if (components::beginMenubarMenu("View##AcmMenubar_View")) {
            renderViewMenu();
            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }
}

void AcmMenubar::renderFileMenu() {
    if (ImGui::MenuItem("New Collections")) {
    }
    if (ImGui::MenuItem("New Request")) {
    }
    if (ImGui::MenuItem("Open Collections")) {
    }
    ImGui::Separator();
    if (ImGui::MenuItem("Settings")) {
    }
}

void AcmMenubar::renderEditMenu() {
    if (ImGui::MenuItem("Undo")) {
    }
    if (ImGui::MenuItem("Redo")) {
    }
    ImGui::Separator();
    if (ImGui::MenuItem("Cut")) {
    }
    if (ImGui::MenuItem("Copy")) {
    }
    if (ImGui::MenuItem("Paste")) {
    }
}

void AcmMenubar::renderViewMenu() {
    if (ImGui::MenuItem("Toggle Sidebar")) {
    }
    if (ImGui::MenuItem("Toggle Console")) {
    }
    ImGui::Separator();
    if (ImGui::MenuItem("Zoom In")) {
    }
    if (ImGui::MenuItem("Zoom Out")) {
    }
}
