#include "iws_modal_create_server.hpp"

#include <imgui.h>

#include "utils/imgui/colors.hpp"
#include "utils/imgui/styles_scoped.hpp"
#include "utils/imgui/window_flags_builder.hpp"

bool IwsModalCreateServer::begin() {
    ImGuiWindowFlags modalFlags = WindowFlagsBuilder().addStatic().build();

    StylesScoped modalStyles;
    modalStyles.pushStyleColor(ImGuiCol_ModalWindowDimBg, COLOR_BLACK_OVERLAY);
    modalStyles.pushStyleColor(ImGuiCol_PopupBg, COLOR_DARK_GREY);

    return ImGui::BeginPopupModal("IwsModalCreateServer", nullptr, modalFlags);
}

void IwsModalCreateServer::renderContent() {
    ImGui::Text("All those beautiful files will be deleted.\nThis operation cannot be undone!");
    ImGui::Separator();

    static bool dontAskMeNextTime = false;
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 0));
    ImGui::Checkbox("Don't ask me next time", &dontAskMeNextTime);
    ImGui::PopStyleVar();

    if (ImGui::Button("OK", ImVec2(120, 0))) {
        ImGui::CloseCurrentPopup();
    }
    ImGui::SetItemDefaultFocus();
    ImGui::SameLine();
    if (ImGui::Button("Cancel", ImVec2(120, 0))) {
        ImGui::CloseCurrentPopup();
    }
}

void IwsModalCreateServer::end() { ImGui::EndPopup(); }
