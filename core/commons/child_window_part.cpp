#include "child_window_part.hpp"

#include <imgui.h>

void commons::ChildWindowPart::end() { ImGui::EndChild(); }
