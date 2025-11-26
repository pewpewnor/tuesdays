#include "fonts_lifetime.hpp"

#include <imgui-SFML.h>

#include "globals/fonts.hpp"
#include "spdlog/spdlog.h"
#include "utils/assertions.hpp"

void FontsLifetime::onStartup() {
    g::fonts = std::make_unique<g::Fonts>();

    std::filesystem::path assetsPath = "assets";
    std::filesystem::path fontsPath = assetsPath / "fonts";

    spdlog::debug("Loading all fonts...");
    loadSansFonts(fontsPath);
    loadMonoFonts(fontsPath);

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

void FontsLifetime::loadSansFonts(const std::filesystem::path& fontsPath) {
    std::filesystem::path regularPath = fontsPath / "IBMPlexSans-Regular.ttf";
    float fontSize = 20;

    if (Result<ImFont*> result = loadFont(regularPath, fontSize)) {
        g::fonts->sansRegular = result.value();
    } else {
        ASSERT(false, "must successfully load sans font regular");
        spdlog::error("Failed to load sans font regular: ", result.error());
        g::fonts->sansRegular = ImGui::GetIO().FontDefault;
    }

    std::filesystem::path boldPath = fontsPath / "IBMPlexSans-Bold.ttf";
    if (Result<ImFont*> result = loadFont(boldPath, fontSize)) {
        g::fonts->sansBold = result.value();
    } else {
        ASSERT(false, "must successfully load sans font bold");
        spdlog::error("Failed to load sans font bold: ", result.error());
        if (g::fonts->sansRegular != nullptr) {
            g::fonts->sansBold = g::fonts->sansRegular;
        } else {
            g::fonts->sansBold = ImGui::GetIO().FontDefault;
        }
    }
}

void FontsLifetime::loadMonoFonts(const std::filesystem::path& fontsPath) {
    std::filesystem::path regularPath = fontsPath / "GeistMono-Regular.ttf";
    float fontSize = 20;

    if (Result<ImFont*> result = loadFont(regularPath, fontSize)) {
        g::fonts->monoRegular = result.value();
    } else {
        ASSERT(false, "must successfully load mono font regular");
        spdlog::error("Failed to load mono font regular: ", result.error());
        g::fonts->monoRegular = ImGui::GetIO().FontDefault;
    }

    std::filesystem::path boldPath = fontsPath / "IBMPlexSans-Bold.ttf";
    if (Result<ImFont*> result = loadFont(boldPath, fontSize)) {
        g::fonts->monoBold = result.value();
    } else {
        ASSERT(false, "must successfully load mono font bold");
        spdlog::error("Failed to load mono font bold: ", result.error());
        if (g::fonts->monoRegular != nullptr) {
            g::fonts->monoBold = g::fonts->monoRegular;
        } else {
            g::fonts->monoBold = ImGui::GetIO().FontDefault;
        }
    }
}

Result<ImFont*> FontsLifetime::loadFont(const std::filesystem::path& fontFilePath, float fontSize) {
    if (!std::filesystem::exists(fontFilePath)) {
        return std::unexpected("configured UI font doesn't exist in the path");
    }
    return ImGui::GetIO().Fonts->AddFontFromFileTTF(fontFilePath.c_str(), fontSize);
}
