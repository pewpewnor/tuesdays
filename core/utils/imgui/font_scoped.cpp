#include "font_scoped.hpp"

#include <imgui.h>

FontScoped::FontScoped(ImFont* font) { ImGui::PushFont(font); }

FontScoped::~FontScoped() { ImGui::PopFont(); }
