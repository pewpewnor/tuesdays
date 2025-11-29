#include "textures_lifetime.hpp"

#include <imgui.h>
#include <lunasvg.h>
#include <spdlog/spdlog.h>

#include <SFML/Graphics/Image.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdint>
#include <optional>

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

void TexturesLifetime::loadTextureFromSvg(sf::Texture& texture, std::string_view fileName,
                                          const std::optional<ImVec4>& recolor) {
    ASSERT(fileName.ends_with(".svg"), "must be svg to specifically load svg");

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
    if (recolor.has_value()) {
        auto r = static_cast<uint8_t>(recolor->x * 255);
        auto g = static_cast<uint8_t>(recolor->y * 255);
        auto b = static_cast<uint8_t>(recolor->z * 255);
        for (unsigned int j = 0; j < image.getSize().y; ++j) {
            for (unsigned int i = 0; i < image.getSize().x; ++i) {
                sf::Color pixel = image.getPixel(sf::Vector2u(i, j));
                if (pixel.a > 0) {
                    pixel.r = r;
                    pixel.g = g;
                    pixel.b = b;
                    image.setPixel(sf::Vector2u(i, j), pixel);
                }
            }
        }
    }
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
