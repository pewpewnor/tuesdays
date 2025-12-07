#include "textures_lifetime.hpp"

#include <spdlog/spdlog.h>

#include "globals/textures.hpp"
#include "utils/assertions.hpp"

void TexturesLifetime::onStartup() {
    g::textures = std::make_unique<g::Textures>();
    spdlog::debug("Loading all textures ...");
    loadTextures();
    spdlog::debug("Loaded all textures");
}

void TexturesLifetime::onShutdown() { g::textures.reset(); }

void TexturesLifetime::loadTextureFromMemory(sf::Texture& texture, const void* data, size_t size,
                                             std::string_view textureName) {
    if (!texture.loadFromMemory(data, size)) {
        ASSERT_UNREACHABLE("must successfully load texture");
        spdlog::warn("Failed to load texture '{}': error when loading from memory", textureName);
        return;
    }
    if (!smoothenTexture(texture)) {
        ASSERT_UNREACHABLE("must successfully smoothen texture");
        spdlog::warn("Failed to smoothen texture when loading texture '{}'", textureName);
    }
}

bool TexturesLifetime::smoothenTexture(sf::Texture& texture) {
    texture.setSmooth(true);
    return texture.generateMipmap();
}
