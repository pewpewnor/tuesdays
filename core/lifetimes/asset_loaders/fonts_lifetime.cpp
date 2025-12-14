#include "fonts_lifetime.hpp"

#include <imgui-SFML.h>
#include <spdlog/spdlog.h>

#include <memory>

#include "globals/fonts.hpp"
#include "utils/assertions.hpp"
#include "utils/deleters.hpp"

void FontsLifetime::onStartup() {
    g::fonts = std::make_unique<g::Fonts>();

    spdlog::debug("Loading all fonts ...");
    loadSansFonts();
    loadMonoFonts();

    if (!ImGui::SFML::UpdateFontTexture()) {
        std::shared_ptr<ImFont> defaultFont = getDefaultFont();
        g::fonts->sansRegular = defaultFont;
        g::fonts->sansSemiBold = defaultFont;
        g::fonts->sansBold = defaultFont;
        g::fonts->monoRegular = defaultFont;
        g::fonts->monoBold = defaultFont;
        spdlog::warn("Failed to load all fonts when updating font texture");
    }
}

void FontsLifetime::onShutdown() { g::fonts.reset(); }

std::shared_ptr<ImFont> FontsLifetime::getDefaultFont() {
    return std::shared_ptr<ImFont>(ImGui::GetIO().FontDefault, NoOpDeleter());
}

std::optional<std::shared_ptr<ImFont>> FontsLifetime::loadFontFromMemory(
    const void* data, size_t dataSize, float fontSizePixels, std::string_view fontName) {
    ImFontConfig config;
    config.FontDataOwnedByAtlas = false;

    ImFont* font = ImGui::GetIO().Fonts->AddFontFromMemoryTTF(
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-const-cast)
        const_cast<void*>(data), static_cast<int>(dataSize), fontSizePixels, &config);

    if (font == nullptr) {
        ASSERT_UNREACHABLE("must successfully load sans font regular");
        spdlog::warn("Failed to load font '{}'", fontName);
        return {};
    }
    return std::shared_ptr<ImFont>(font, NoOpDeleter());
}
