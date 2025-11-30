#include "iws_menus.hpp"

#include <imgui.h>

IwsMenuFile::IwsMenuFile() : components::Menu("File##IwsMenubar_File") {}

void IwsMenuFile::renderContent() {
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

IwsMenuEdit::IwsMenuEdit() : components::Menu("Edit##IwsMenubar_Edit") {}

void IwsMenuView::renderContent() {
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

IwsMenuView::IwsMenuView() : components::Menu("View##IwsMenubar_View") {}

void IwsMenuEdit::renderContent() {
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
