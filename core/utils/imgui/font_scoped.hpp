#pragma once

#include <imgui.h>

class FontScoped {
public:
    FontScoped(ImFont* font);

    FontScoped(const FontScoped&) = delete;
    FontScoped(FontScoped&&) = delete;
    FontScoped& operator=(const FontScoped&) = delete;
    FontScoped& operator=(FontScoped&&) = delete;

    ~FontScoped();
};
