#include "iws_modal_create_server.hpp"

#include <imgui.h>

#include "universal/states/current_app.hpp"

bool IwsModalCreateServer::shouldRender() { return univ::currentAppIsIws(); }

void IwsModalCreateServer::onRender() {
    if (ImGui::BeginPopupModal("IwsModalCreateServer", nullptr,
                               ImGuiWindowFlags_AlwaysAutoResize)) {
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
        ImGui::EndPopup();
    }
}
