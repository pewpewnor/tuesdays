#include "iws_menu_parts.hpp"

#include <imgui.h>

IwsMenuPartFile::IwsMenuPartFile() : components::MenuPart("File##IwsMenuPartbar_File") {}

void IwsMenuPartFile::renderContent() {
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

IwsMenuPartEdit::IwsMenuPartEdit() : components::MenuPart("Edit##IwsMenuPartbar_Edit") {}

void IwsMenuPartView::renderContent() {
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

IwsMenuPartView::IwsMenuPartView() : components::MenuPart("View##IwsMenuPartbar_View") {}

void IwsMenuPartEdit::renderContent() {
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
