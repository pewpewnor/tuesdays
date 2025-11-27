#include "textures_lifetime.hpp"

#include <lunasvg.h>

#include <SFML/Graphics/Image.hpp>

#include "SFML/System/Vector2.hpp"
#include "globals/textures.hpp"
#include "spdlog/spdlog.h"
#include "utils/assertions.hpp"

std::filesystem::path TexturesLifetime::imagesPath = std::filesystem::path("assets") / "images";

void TexturesLifetime::onStartup() {
    g::textures = std::make_unique<g::Textures>();
    spdlog::debug("Loading all textures...");

    loadTextureFromSvg(g::textures->lightningBoltIconBlack, "lightning-bolt-icon-black.svg");
    loadTextureFromSvg(g::textures->lightningBoltIconWhite, "lightning-bolt-icon-white.svg");
    loadTextureFromSvg(g::textures->radarIconBlack, "radar-icon-black.svg");
    loadTextureFromSvg(g::textures->radarIconWhite, "radar-icon-white.svg");

    spdlog::debug("Loaded all textures");
}

void TexturesLifetime::onShutdown() { g::textures.reset(); }

void TexturesLifetime::loadTexture(sf::Texture& texture, std::string_view fileName) {
    ASSERT(!fileName.ends_with(".svg"), "must not be svg");
    if (!texture.loadFromFile(imagesPath / fileName, true)) {
        spdlog::error("Failed to load texture '{}': error when loading from file", fileName);
        return;
    }
    if (!smoothenTexture(texture)) {
        spdlog::error("Failed to generate mipmap when loading texture '{}'", fileName);
    }
}

void TexturesLifetime::loadTextureFromSvg(sf::Texture& texture, std::string_view fileName) {
    ASSERT(fileName.ends_with(".svg"), "must be svg");
    std::unique_ptr<lunasvg::Document> document =
        lunasvg::Document::loadFromFile(imagesPath / fileName);
    if (document == nullptr) {
        spdlog::error("Failed to load texture '{}': error when loading from file", fileName);
        return;
    }
    lunasvg::Bitmap bitmap = document->renderToBitmap();
    if (bitmap.isNull()) {
        spdlog::error("Failed to load texture '{}': bitmap is null", fileName);
        return;
    }
    sf::Image image;
    image.resize(sf::Vector2u(bitmap.width(), bitmap.height()), bitmap.data());
    if (!texture.loadFromImage(image, true)) {
        spdlog::error("Failed to load texture '{}': error when loading from texture", fileName);
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
