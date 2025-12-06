#include "iws_create_server_group_modal.hpp"

#include <imgui.h>

#include "components/image_buttons.hpp"
#include "globals/engine_state.hpp"
#include "globals/fonts.hpp"
#include "iws/states/iws_state.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/font_scoped.hpp"
#include "utils/imgui/helpers.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

bool IwsCreateServerGroupModal::begin() {
    ImGuiWindowFlags modalFlags = WindowFlagsBuilder().addStatic().build();

    StylesScoped modalStyles;
    modalStyles.pushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(18, 18));
    modalStyles.pushStyleVar(ImGuiStyleVar_WindowRounding, 4);
    modalStyles.pushStyleColor(ImGuiCol_ModalWindowDimBg, COLOR_BLACK_OVERLAY);
    modalStyles.pushStyleColor(ImGuiCol_PopupBg, COLOR_DARK_GREY);

    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(ImVec2(center.x, center.y - (center.y / 2)), ImGuiCond_Always,
                            ImVec2(0.5, 0.5));

    return ImGui::BeginPopupModal("IwsModalCreateServer", nullptr, modalFlags);
}

void IwsCreateServerGroupModal::displayContent() {
    StylesScoped contentStyles;
    contentStyles.pushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(8, 12));

    {
        FontScoped font(g::fonts->sansBold.get());
        ImGui::TextUnformatted("NEW SERVER");
    }

    ImGui::SameLine();

    constexpr float crossButtonSize = 14;
    putNexItemAtTheEndOfWindow(crossButtonSize);
    if (components::crossIconButton("IwsModalCreateServer_Cross", crossButtonSize)) {
        closePopup();
        return;
    };

    ImGui::Separator();

    {
        StylesScoped serverNameInputStyles;
        serverNameInputStyles.pushStyleVarY(ImGuiStyleVar_ItemSpacing, 8);

        {
            FontScoped font(g::fonts->sansMedium.get());
            ImGui::TextUnformatted("Server Name");
        }

        setNextItemWidthAsLongAsPossible();
        ImGui::InputText("##IwsModalCreateServer_ServerName", serverNameBuffer_.data(),
                         serverNameBuffer_.size());

        if (violatedServerNameRequired_) {
            ImGui::TextColored(COLOR_ORANGE, "name is required");
        }
    }

    ImGui::Dummy(ImVec2(0, 8));

    ImGui::Dummy(ImVec2(132, 0));

    ImGui::SameLine();

    {
        StylesScoped cancelButtonStyles;
        cancelButtonStyles.pushStyleVar(ImGuiStyleVar_FrameBorderSize, 1);
        cancelButtonStyles.pushStyleVar(ImGuiStyleVar_FrameRounding, 4);
        cancelButtonStyles.pushStyleColor(ImGuiCol_Border, COLOR_FG_MUTED);

        if (ImGui::Button("Cancel", ImVec2(96, 36))) {
            closePopup();
            return;
        }
    }

    ImGui::SameLine();

    StylesScoped okButtonStyles;
    okButtonStyles.pushStyleVar(ImGuiStyleVar_FrameRounding, 4);
    okButtonStyles.pushStyleColor(ImGuiCol_Button, COLOR_AZURE_SHADOW);
    okButtonStyles.pushStyleColor(ImGuiCol_ButtonHovered, COLOR_AZURE);
    okButtonStyles.pushStyleColor(ImGuiCol_ButtonActive, COLOR_AZURE);

    if (ImGui::Button("OK", ImVec2(96, 36))) {
        std::string serverName(serverNameBuffer_.data());

        if (serverName.length() < 1) {
            resetValidations();
            violatedServerNameRequired_ = true;
            g::engine->sendRefreshSignal();
        } else {
            iws::state->serverGroups.emplace_back(serverName);
            closePopup();
            return;
        }
    }
}

void IwsCreateServerGroupModal::endOfDisplay() { ImGui::EndPopup(); }

void IwsCreateServerGroupModal::resetValidations() { violatedServerNameRequired_ = false; }

void IwsCreateServerGroupModal::closePopup() {
    iws::state->showCreateSeverModal = false;
    ImGui::CloseCurrentPopup();
}
