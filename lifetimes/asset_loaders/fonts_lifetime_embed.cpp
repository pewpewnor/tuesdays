#include <array>

#include "fonts_lifetime.hpp"
#include "globals/fonts.hpp"
#include "utils/macros.hpp"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"

void FontsLifetime::loadSansFonts() {
    static constexpr auto SANS_REGULAR_TTF = std::to_array<unsigned char>({
#embed "assets/fonts/Geist-Regular.ttf"
    });
    if (auto result =
            loadFontFromMemory(SANS_REGULAR_TTF.data(), static_cast<int>(SANS_REGULAR_TTF.size()),
                               REGULAR_FONT_SIZE)) {
        g::fonts->sansRegular = result.value();
    } else {
        logFontLoadError(NAME_OF(SANS_REGULAR_TTF), result.error());
        g::fonts->sansRegular = getDefaultFont();
    }

    static constexpr auto SANS_SEMIBOLD_TTF = std::to_array<unsigned char>({
#embed "assets/fonts/Geist-SemiBold.ttf"
    });
    if (auto result =
            loadFontFromMemory(SANS_SEMIBOLD_TTF.data(), static_cast<int>(SANS_SEMIBOLD_TTF.size()),
                               REGULAR_FONT_SIZE)) {
        g::fonts->sansSemiBold = result.value();
    } else {
        logFontLoadError(NAME_OF(SANS_SEMIBOLD_TTF), result.error());
        g::fonts->sansSemiBold = g::fonts->sansRegular;
    }

    static constexpr auto SANS_BOLD_TTF = std::to_array<unsigned char>({
#embed "assets/fonts/Geist-Bold.ttf"
    });
    if (auto result = loadFontFromMemory(
            SANS_BOLD_TTF.data(), static_cast<int>(SANS_BOLD_TTF.size()), REGULAR_FONT_SIZE)) {
        g::fonts->sansBold = result.value();
    } else {
        logFontLoadError(NAME_OF(SANS_BOLD_TTF), result.error());
        g::fonts->sansBold = g::fonts->sansSemiBold;
    }
}

void FontsLifetime::loadMonoFonts() {
    static constexpr auto MONO_REGULAR_TTF = std::to_array<unsigned char>({
#embed "assets/fonts/GeistMono-Regular.ttf"
    });
    if (auto result =
            loadFontFromMemory(MONO_REGULAR_TTF.data(), static_cast<int>(MONO_REGULAR_TTF.size()),
                               REGULAR_FONT_SIZE)) {
        g::fonts->monoRegular = result.value();
    } else {
        logFontLoadError(NAME_OF(MONO_REGULAR_TTF), result.error());
        g::fonts->monoRegular = getDefaultFont();
    }

    static constexpr auto MONO_BOLD_TTF = std::to_array<unsigned char>({
#embed "assets/fonts/GeistMono-Bold.ttf"
    });
    if (auto result = loadFontFromMemory(
            MONO_BOLD_TTF.data(), static_cast<int>(MONO_BOLD_TTF.size()), REGULAR_FONT_SIZE)) {
        g::fonts->monoBold = result.value();
    } else {
        logFontLoadError(NAME_OF(MONO_BOLD_TTF), result.error());
        g::fonts->monoBold = g::fonts->monoRegular;
    }
}

#pragma clang diagnostic pop
