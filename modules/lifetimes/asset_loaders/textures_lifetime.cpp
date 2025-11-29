#include "textures_lifetime.hpp"

#include <imgui.h>
#include <spdlog/spdlog.h>

#include <SFML/Graphics/Image.hpp>
#include <SFML/System/Vector2.hpp>

#include "globals/textures.hpp"
#include "utils/assertions.hpp"

std::filesystem::path TexturesLifetime::imagesPath = std::filesystem::path("assets") / "images";

void TexturesLifetime::onStartup() {
    g::textures = std::make_unique<g::Textures>();
    spdlog::debug("Loading all textures...");

    loadTexture(g::textures->lightningBoltIconWhite, "lightning-bolt-icon-white.png");
    loadTexture(g::textures->signalTowerIconWhite, "signal-tower-icon-white.png");

    spdlog::debug("Loaded all textures");
}

void TexturesLifetime::onShutdown() { g::textures.reset(); }

void TexturesLifetime::loadTexture(sf::Texture& texture, std::string_view fileName) {
    ASSERT(!fileName.ends_with(".svg"), "must not be svg to automatically load from file");

    if (!texture.loadFromFile(imagesPath / fileName, true)) {
        spdlog::error("Failed to load texture '{}': error when loading from file", fileName);
        return;
    }
    if (!smoothenTexture(texture)) {
        spdlog::error("Failed to generate mipmap when loading texture '{}'", fileName);
    }
}

bool TexturesLifetime::smoothenTexture(sf::Texture& texture) {
    texture.setSmooth(true);
    return texture.generateMipmap();
}
