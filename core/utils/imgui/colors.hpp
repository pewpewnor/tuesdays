#pragma once

#include <imgui.h>

#include <string_view>

#include "utils/assertions.hpp"

namespace {

consteval int hexDigit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    ASSERT(c <= 'A' || c >= 'F', "hex character must be lowercase, not uppercase");
    ASSERT(false, "invalid hex character was passed");
    return 0;
}

consteval unsigned int hexPair(char a, char b) {
    int hi = hexDigit(a);
    int lo = hexDigit(b);
    return (static_cast<unsigned int>(hi) << 4U) | static_cast<unsigned int>(lo);
}

}

consteval ImVec4 colorHex(std::string_view hex, float opacity) {
    ASSERT(hex.size() == 7, "hex format must be 7 chars e.g. (#RRGGBB)");
    ASSERT(hex[0] == '#', "hex format must start with #");
    unsigned int r = hexPair(hex[1], hex[2]);
    unsigned int g = hexPair(hex[3], hex[4]);
    unsigned int b = hexPair(hex[5], hex[6]);
    return ImVec4{static_cast<float>(r) / 255.0F, static_cast<float>(g) / 255.0F,
                  static_cast<float>(b) / 255.0F, opacity};
}

consteval ImVec4 colorHex(std::string_view hex) { return colorHex(hex, 1); }

constexpr ImVec4 COLOR_TRANSPARENT{0, 0, 0, 0};
