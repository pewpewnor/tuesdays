#include "iws_create_server_modal_part.hpp"

#include <imgui.h>

#include "globals/engine_state.hpp"
#include "globals/fonts.hpp"
#include "iws/events/update_server_groups.hpp"
#include "iws/states/iws_state.hpp"
#include "universal/components/image_buttons.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/font_scoped.hpp"
#include "utils/imgui/helpers.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

bool IwsCreateServerModalPart::begin() {
    ImGuiWindowFlags modalFlags = WindowFlagsBuilder().addAlwaysAutoResize().addStatic().build();

    StylesScoped modalStyles;
    modalStyles.pushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(18, 18));
    modalStyles.pushStyleVar(ImGuiStyleVar_WindowRounding, 4);
    modalStyles.pushStyleColor(ImGuiCol_ModalWindowDimBg, COLOR_BLACK_OVERLAY);
    modalStyles.pushStyleColor(ImGuiCol_PopupBg, COLOR_DARK_GRAY);

    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(ImVec2(center.x, center.y - (center.y / 2)), ImGuiCond_Always,
                            ImVec2(0.5, 0.5));

    return ImGui::BeginPopupModal("IwsCreateServerModal", nullptr, modalFlags);
}

void IwsCreateServerModalPart::displayContent() {
    StylesScoped contentStyles;
    contentStyles.pushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(8, 12));

    {
        FontScoped font(g::fonts->sansBold.get());
        ImGui::TextUnformatted("NEW SERVER");
    }

    ImGui::SameLine();

    constexpr float crossButtonSize = 14;
    putNexItemAtTheEndOfWindow(crossButtonSize);
    if (components::crossIconButton("IwsCreateServerModal_Cross", crossButtonSize)) {
        closePopup();
        return;
    };

    ImGui::Separator();

    {
        StylesScoped serverNameInputStyles;
        serverNameInputStyles.pushStyleVarY(ImGuiStyleVar_ItemSpacing, 8);

        {
            FontScoped font(g::fonts->sansSemiBold.get());
            ImGui::TextUnformatted("Server Name");
        }

        setNextItemWidthAsLongAsPossible();
        ImGui::InputText("##IwsCreateServerModal_ServerName", serverNameBuffer_.data(),
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
            g::engine->sendRefreshSignal();  // for auto resize
        } else {
            iws::state->servers.push_back(std::make_shared<iws::Server>(serverName));
            iws::events::updateServerGroups();
            closePopup();
            return;
        }
    }
}

void IwsCreateServerModalPart::endOfDisplay() { ImGui::EndPopup(); }

void IwsCreateServerModalPart::resetValidations() { violatedServerNameRequired_ = false; }

void IwsCreateServerModalPart::closePopup() {
    iws::state->showCreateServerModal = false;
    ImGui::CloseCurrentPopup();
}
