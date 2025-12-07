#include "child_window_part.hpp"

#include <imgui.h>

void commons::ChildWindowPart::display() {
    if (beginChildWindow()) {
        displayChildWindowContent();
    }
    ImGui::EndChild();
}
