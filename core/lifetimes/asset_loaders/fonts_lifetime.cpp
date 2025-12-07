#include "fonts_lifetime.hpp"

#include <imgui-SFML.h>
#include <spdlog/spdlog.h>

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
    ASSERT_UNREACHABLE("must successfully load sans font regular");
    spdlog::warn("Failed to load font '{}': {}", fontName, errorMsg);
}
