#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"

#include "fonts_lifetime.hpp"

#include <imgui-SFML.h>
#include <spdlog/spdlog.h>

#include <array>
#include <expected>
#include <memory>

#include "globals/fonts.hpp"
#include "utils/assertions.hpp"
#include "utils/deleters.hpp"

void FontsLifetime::onStartup() {
    g::fonts = std::make_unique<g::Fonts>();

    spdlog::debug("Loading all fonts ...");
    loadSansFonts();
    loadMonoFonts();

    if (ImGui::SFML::UpdateFontTexture()) {
        spdlog::debug("Sucessfully loaded all fonts");
    } else {
        std::shared_ptr<ImFont> defaultFont = getDefaultFont();
        g::fonts->sansRegular = defaultFont;
        g::fonts->monoRegular = defaultFont;
        g::fonts->monoBold = defaultFont;
        spdlog::error("Failed to load all fonts when updating font texture");
    }
}

void FontsLifetime::onShutdown() { g::fonts.reset(); }

std::shared_ptr<ImFont> FontsLifetime::getDefaultFont() {
    return std::shared_ptr<ImFont>(ImGui::GetIO().FontDefault, NoOpDeleter());
}

Result<std::shared_ptr<ImFont>> FontsLifetime::loadFontFromMemory(const void* data, int dataSize,
                                                                  float fontSizePixels) {
    ImFontConfig config;
    config.FontDataOwnedByAtlas = false;

    // NOLINTNEXTLINE(cppcoreguidelines-pro-type-const-cast)
    ImFont* font = ImGui::GetIO().Fonts->AddFontFromMemoryTTF(const_cast<void*>(data), dataSize,
                                                              fontSizePixels, &config);

    if (font == nullptr) {
        return std::unexpected("error when adding font from memory");
    }
    return std::shared_ptr<ImFont>(font, NoOpDeleter());
}

void FontsLifetime::logFontLoadError(std::string_view fontName, const std::string& errorMsg) {
    spdlog::error("Failed to load font {}: {}", fontName, errorMsg);
    ASSERT(false, "must successfully load sans font regular");
}

void FontsLifetime::loadSansFonts() {
    {
        static constexpr auto DATA = std::to_array<unsigned char>({
#embed "assets/fonts/Geist-Regular.ttf"
        });
        if (auto result =
                loadFontFromMemory(DATA.data(), static_cast<int>(DATA.size()), REGULAR_FONT_SIZE)) {
            g::fonts->sansRegular = result.value();
        } else {
            logFontLoadError("sans regular", result.error());
            g::fonts->sansRegular = getDefaultFont();
        }
    }

    {
        static constexpr auto DATA = std::to_array<unsigned char>({
#embed "assets/fonts/Geist-SemiBold.ttf"
        });
        if (auto result =
                loadFontFromMemory(DATA.data(), static_cast<int>(DATA.size()), REGULAR_FONT_SIZE)) {
            g::fonts->sansMedium = result.value();
        } else {
            logFontLoadError("sans medium", result.error());
            g::fonts->sansMedium = g::fonts->sansRegular;
        }
    }

    {
        static constexpr auto DATA = std::to_array<unsigned char>({
#embed "assets/fonts/Geist-Bold.ttf"
        });
        if (auto result =
                loadFontFromMemory(DATA.data(), static_cast<int>(DATA.size()), REGULAR_FONT_SIZE)) {
            g::fonts->sansBold = result.value();
        } else {
            logFontLoadError("sans bold", result.error());
            g::fonts->sansBold = g::fonts->sansMedium;
        }
    }
}

void FontsLifetime::loadMonoFonts() {
    {
        static constexpr auto DATA = std::to_array<unsigned char>({
#embed "assets/fonts/GeistMono-Regular.ttf"
        });
        if (auto result =
                loadFontFromMemory(DATA.data(), static_cast<int>(DATA.size()), REGULAR_FONT_SIZE)) {
            g::fonts->monoRegular = result.value();
        } else {
            logFontLoadError("mono regular", result.error());
            g::fonts->monoRegular = getDefaultFont();
        }
    }

    {
        static constexpr auto DATA = std::to_array<unsigned char>({
#embed "assets/fonts/GeistMono-Bold.ttf"
        });
        if (auto result =
                loadFontFromMemory(DATA.data(), static_cast<int>(DATA.size()), REGULAR_FONT_SIZE)) {
            g::fonts->monoBold = result.value();
        } else {
            logFontLoadError("mono bold", result.error());
            g::fonts->monoBold = g::fonts->monoRegular;
        }
    }
}

#pragma clang diagnostic pop
