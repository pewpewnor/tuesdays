#pragma once

#include <imgui.h>

#include <string_view>

#include "utils/assertions.hpp"

namespace {

consteval unsigned int hexDigit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    ASSERT(c <= 'A' || c >= 'F', "hex characters must be lowercase, not uppercase");
    ASSERT(false, "invalid hex character was passed");
    return 0;
}

consteval unsigned int hexPair(char a, char b) {
    unsigned int hi = hexDigit(a);
    unsigned int lo = hexDigit(b);
    return (hi << 4U) | lo;
}

}

consteval ImVec4 colorHex(std::string_view hex, float opacity) {
    ASSERT(hex.length() == 7, "hex format must be 7 chars");
    ASSERT(hex[0] == '#', "hex format must start with '#'");
    auto r = static_cast<float>(hexPair(hex[1], hex[2]));
    auto g = static_cast<float>(hexPair(hex[3], hex[4]));
    auto b = static_cast<float>(hexPair(hex[5], hex[6]));
    return ImVec4{r / 255, g / 255, b / 255, opacity};
}

consteval ImVec4 colorHex(std::string_view hex) { return colorHex(hex, 1); }

constexpr ImVec4 COLOR_TRANSPARENT{colorHex("#000000", 0)};
constexpr ImVec4 COLOR_BLACK{colorHex("#000000")};
constexpr ImVec4 COLOR_WHITE{colorHex("#ffffff")};

constexpr ImVec4 COLOR_NIGHT_1{colorHex("#010304")};
constexpr ImVec4 COLOR_NIGHT_2{colorHex("#000303")};
constexpr ImVec4 COLOR_NIGHT_3{colorHex("#171717")};
constexpr ImVec4 COLOR_NIGHT_4{colorHex("#020507")};
constexpr ImVec4 COLOR_DARK_GREY{colorHex("#262626")};

constexpr ImVec4 COLOR_AZURE{colorHex("#239cff")};
constexpr ImVec4 COLOR_AZURE_SHADOW{colorHex("#1c7ecd")};
constexpr ImVec4 COLOR_GREEN_TEAL{colorHex("#12c281")};
constexpr ImVec4 COLOR_ORANGE{colorHex("#ff6728")};
constexpr ImVec4 COLOR_CHOCOLATE{colorHex("#4e210f")};

constexpr ImVec4 COLOR_TEXT_MUTED{colorHex("#8d9aa3")};
constexpr ImVec4 COLOR_TEXT_FG{colorHex("#f0e9e4")};
