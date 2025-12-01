#include "fonts_lifetime.hpp"

#include <imgui-SFML.h>

#include <expected>
#include <memory>

#include "globals/fonts.hpp"
#include "spdlog/spdlog.h"
#include "utils/assertions.hpp"
#include "utils/deleters.hpp"

namespace {}

std::filesystem::path FontsLifetime::fontsPath = std::filesystem::path("assets") / "fonts";

void FontsLifetime::onStartup() {
    g::fonts = std::make_unique<g::Fonts>();

    spdlog::debug("Loading all fonts...");
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

Result<std::shared_ptr<ImFont>> FontsLifetime::loadFont(const std::filesystem::path& fontFilePath,
                                                        float fontSize) {
    if (!std::filesystem::exists(fontFilePath)) {
        return std::unexpected("font file does not exist");
    }
    ImFont* font = ImGui::GetIO().Fonts->AddFontFromFileTTF(fontFilePath.c_str(), fontSize);
    if (font == nullptr) {
        return std::unexpected("error when adding font from ttf file");
    }
    return std::shared_ptr<ImFont>(font, NoOpDeleter());
}

void FontsLifetime::loadSansFonts() {
    std::filesystem::path regularPath = fontsPath / sansRegularFileName;

    if (Result<std::shared_ptr<ImFont>> result = loadFont(regularPath, MEDIUM_FONT_SIZE)) {
        g::fonts->sansRegular = result.value();
    } else {
        spdlog::error("Failed to load sans font regular: {}", result.error());
        ASSERT(false, "must successfully load sans font regular");
        g::fonts->sansRegular = getDefaultFont();
    }

    std::filesystem::path boldPath = fontsPath / sansBoldFileName;
    if (Result<std::shared_ptr<ImFont>> result = loadFont(boldPath, MEDIUM_FONT_SIZE)) {
        g::fonts->sansBold = result.value();
    } else {
        spdlog::error("Failed to load sans font bold: {}", result.error());
        ASSERT(false, "must successfully load sans font bold");
        if (g::fonts->sansRegular != nullptr) {
            g::fonts->sansBold = g::fonts->sansRegular;
        } else {
            g::fonts->sansBold = getDefaultFont();
        }
    }
    if (Result<std::shared_ptr<ImFont>> result = loadFont(boldPath, LARGE_FONT_SIZE)) {
        g::fonts->sansBoldLarge = result.value();
    } else {
        spdlog::error("Failed to load sans font bold: {}", result.error());
        ASSERT(false, "must successfully load sans font bold");
        g::fonts->sansBoldLarge = g::fonts->sansBold;
    }
}

void FontsLifetime::loadMonoFonts() {
    std::filesystem::path regularPath = fontsPath / monoRegularFileName;

    if (Result<std::shared_ptr<ImFont>> result = loadFont(regularPath, MEDIUM_FONT_SIZE)) {
        g::fonts->monoRegular = result.value();
    } else {
        spdlog::error("Failed to load mono font regular: {}", result.error());
        ASSERT(false, "must successfully load mono font regular");
        g::fonts->monoRegular = getDefaultFont();
    }

    std::filesystem::path boldPath = fontsPath / monoBoldFileName;
    if (Result<std::shared_ptr<ImFont>> result = loadFont(boldPath, MEDIUM_FONT_SIZE)) {
        g::fonts->monoBold = result.value();
    } else {
        spdlog::error("Failed to load mono font bold: {}", result.error());
        ASSERT(false, "must successfully load mono font bold");
        if (g::fonts->monoRegular != nullptr) {
            g::fonts->monoBold = g::fonts->monoRegular;
        } else {
            g::fonts->monoBold = getDefaultFont();
        }
    }
}
