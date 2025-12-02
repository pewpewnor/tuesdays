#include "iws_modal_create_server.hpp"

#include <imgui.h>

#include <array>

#include "commons/components.hpp"
#include "globals/fonts.hpp"
#include "utils/imgui/colors.hpp"
#include "utils/imgui/font_scoped.hpp"
#include "utils/imgui/helpers.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

bool IwsModalCreateServer::begin() {
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

void IwsModalCreateServer::renderContent() {
    StylesScoped contentStyles;
    contentStyles.pushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4, 12));

    {
        FontScoped font(g::fonts->sansBold.get());
        ImGui::TextUnformatted("NEW SERVER");
    }

    ImGui::SameLine();

    constexpr float crossButtonSize = 14;
    putNexItemAtTheEndOfWindow(crossButtonSize);
    if (components::crossIconButton("IwsModalCreateServer_Cross", crossButtonSize)) {
        ImGui::CloseCurrentPopup();
    };

    ImGui::Separator();

    {
        StylesScoped inputServerNameStyles;
        inputServerNameStyles.pushStyleVarY(ImGuiStyleVar_ItemSpacing, 8);

        {
            FontScoped font(g::fonts->sansMedium.get());
            ImGui::TextUnformatted("Server Name");
        }

        setNextItemWidthAsLongAsPossible();
        std::array<char, 255> buffer{'\0'};
        ImGui::InputText("##IwsModalCreateServer_ServerName", buffer.data(), buffer.size());
    }

    ImGui::Dummy(ImVec2(120, 0));

    ImGui::SameLine();

    StylesScoped cancelButtonStyles;

    if (ImGui::Button("Cancel", ImVec2(80, 30))) {
        ImGui::CloseCurrentPopup();
    }

    ImGui::SameLine();

    StylesScoped okButtonStyles;
    okButtonStyles.pushStyleColor(ImGuiCol_Button, COLOR_AZURE_SHADOW);
    okButtonStyles.pushStyleColor(ImGuiCol_ButtonHovered, COLOR_AZURE);
    okButtonStyles.pushStyleColor(ImGuiCol_ButtonActive, COLOR_AZURE);

    if (ImGui::Button("OK", ImVec2(80, 30))) {
        ImGui::CloseCurrentPopup();
    }
}

void IwsModalCreateServer::end() { ImGui::EndPopup(); }
