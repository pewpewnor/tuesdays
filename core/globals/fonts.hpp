#pragma once

#include <imgui.h>

#include <memory>

namespace g {

struct Fonts {
    std::shared_ptr<ImFont> sansRegular;
    std::shared_ptr<ImFont> sansMedium;
    std::shared_ptr<ImFont> sansBold;
    std::shared_ptr<ImFont> monoRegular;
    std::shared_ptr<ImFont> monoBold;
};

inline std::unique_ptr<g::Fonts> fonts;

}
