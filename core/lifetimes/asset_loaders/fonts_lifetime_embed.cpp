#include <array>

#include "fonts_lifetime.hpp"
#include "globals/fonts.hpp"
#include "utils/macros.hpp"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"

void FontsLifetime::loadSansFonts() {
    static constexpr auto SANS_REGULAR_TTF = std::to_array<uint8_t>({
#embed "assets/fonts/Geist-Regular.ttf"
    });
    if (auto result = loadFontFromMemory(SANS_REGULAR_TTF.data(), SANS_REGULAR_TTF.size(),
                                         REGULAR_FONT_SIZE, NAME_OF(SANS_REGULAR_TTF))) {
        g::fonts->sansRegular = result.value();
    } else {
        g::fonts->sansRegular = getDefaultFont();
    }

    static constexpr auto SANS_SEMIBOLD_TTF = std::to_array<uint8_t>({
#embed "assets/fonts/Geist-SemiBold.ttf"
    });
    if (auto result = loadFontFromMemory(SANS_SEMIBOLD_TTF.data(), SANS_SEMIBOLD_TTF.size(),
                                         REGULAR_FONT_SIZE, NAME_OF(SANS_SEMIBOLD_TTF))) {
        g::fonts->sansSemiBold = result.value();
    } else {
        g::fonts->sansSemiBold = g::fonts->sansRegular;
    }

    static constexpr auto SANS_BOLD_TTF = std::to_array<uint8_t>({
#embed "assets/fonts/Geist-Bold.ttf"
    });
    if (auto result = loadFontFromMemory(SANS_BOLD_TTF.data(), SANS_BOLD_TTF.size(),
                                         REGULAR_FONT_SIZE, NAME_OF(SANS_BOLD_TTF))) {
        g::fonts->sansBold = result.value();
    } else {
        g::fonts->sansBold = g::fonts->sansSemiBold;
    }
}

void FontsLifetime::loadMonoFonts() {
    static constexpr auto MONO_REGULAR_TTF = std::to_array<uint8_t>({
#embed "assets/fonts/GeistMono-Regular.ttf"
    });
    if (auto result = loadFontFromMemory(MONO_REGULAR_TTF.data(), MONO_REGULAR_TTF.size(),
                                         REGULAR_FONT_SIZE, NAME_OF(MONO_REGULAR_TTF))) {
        g::fonts->monoRegular = result.value();
    } else {
        g::fonts->monoRegular = getDefaultFont();
    }

    static constexpr auto MONO_BOLD_TTF = std::to_array<uint8_t>({
#embed "assets/fonts/GeistMono-Bold.ttf"
    });
    if (auto result = loadFontFromMemory(MONO_BOLD_TTF.data(), MONO_BOLD_TTF.size(),
                                         REGULAR_FONT_SIZE, NAME_OF(MONO_BOLD_TTF))) {
        g::fonts->monoBold = result.value();
    } else {
        g::fonts->monoBold = g::fonts->monoRegular;
    }
}

#pragma clang diagnostic pop
