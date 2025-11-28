#include "fonts_lifetime.hpp"

#include <imgui-SFML.h>

#include <expected>

#include "globals/fonts.hpp"
#include "spdlog/spdlog.h"
#include "utils/assertions.hpp"

std::filesystem::path FontsLifetime::fontsPath = std::filesystem::path("assets") / "fonts";

void FontsLifetime::onStartup() {
    g::fonts = std::make_unique<g::Fonts>();

    spdlog::debug("Loading all fonts...");
    loadSansFonts();
    loadMonoFonts();

    if (ImGui::SFML::UpdateFontTexture()) {
        spdlog::debug("Sucessfully loaded all fonts");
    } else {
        g::fonts->sansRegular = ImGui::GetIO().FontDefault;
        g::fonts->sansBold = ImGui::GetIO().FontDefault;
        g::fonts->monoRegular = ImGui::GetIO().FontDefault;
        g::fonts->monoBold = ImGui::GetIO().FontDefault;
        spdlog::error("Failed to load all fonts when updating font texture");
    }
}

void FontsLifetime::onShutdown() { g::fonts.reset(); }

Result<ImFont*> FontsLifetime::loadFont(const std::filesystem::path& fontFilePath, float fontSize) {
    if (!std::filesystem::exists(fontFilePath)) {
        return std::unexpected("font file does not exist");
    }
    ImFont* font = ImGui::GetIO().Fonts->AddFontFromFileTTF(fontFilePath.c_str(), fontSize);
    if (font == nullptr) {
        return std::unexpected("error when adding font from ttf file");
    }
    return font;
}

void FontsLifetime::loadSansFonts() {
    std::filesystem::path regularPath = fontsPath / sansRegularFileName;
    float fontSize = 20;

    if (Result<ImFont*> result = loadFont(regularPath, fontSize)) {
        g::fonts->sansRegular = result.value();
    } else {
        spdlog::error("Failed to load sans font regular: {}", result.error());
        ASSERT(false, "must successfully load sans font regular");
        g::fonts->sansRegular = ImGui::GetIO().FontDefault;
    }

    std::filesystem::path boldPath = fontsPath / sansBoldFileName;
    if (Result<ImFont*> result = loadFont(boldPath, fontSize)) {
        g::fonts->sansBold = result.value();
    } else {
        spdlog::error("Failed to load sans font bold: {}", result.error());
        ASSERT(false, "must successfully load sans font bold");
        if (g::fonts->sansRegular != nullptr) {
            g::fonts->sansBold = g::fonts->sansRegular;
        } else {
            g::fonts->sansBold = ImGui::GetIO().FontDefault;
        }
    }
}

void FontsLifetime::loadMonoFonts() {
    std::filesystem::path regularPath = fontsPath / monoRegularFileName;
    float fontSize = 20;

    if (Result<ImFont*> result = loadFont(regularPath, fontSize)) {
        g::fonts->monoRegular = result.value();
    } else {
        spdlog::error("Failed to load mono font regular: {}", result.error());
        ASSERT(false, "must successfully load mono font regular");
        g::fonts->monoRegular = ImGui::GetIO().FontDefault;
    }

    std::filesystem::path boldPath = fontsPath / monoBoldFileName;
    if (Result<ImFont*> result = loadFont(boldPath, fontSize)) {
        g::fonts->monoBold = result.value();
    } else {
        spdlog::error("Failed to load mono font bold: {}", result.error());
        ASSERT(false, "must successfully load mono font bold");
        if (g::fonts->monoRegular != nullptr) {
            g::fonts->monoBold = g::fonts->monoRegular;
        } else {
            g::fonts->monoBold = ImGui::GetIO().FontDefault;
        }
    }
}
