#pragma once

#include <imgui.h>

#include <memory>

namespace g {

class Fonts {
public:
    ImFont* sansRegular = nullptr;
    ImFont* sansBold = nullptr;
    ImFont* monoRegular = nullptr;
    ImFont* monoBold = nullptr;
};

inline std::unique_ptr<g::Fonts> fonts;

}
