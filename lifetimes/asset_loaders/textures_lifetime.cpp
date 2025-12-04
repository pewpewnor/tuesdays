#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"

#include "textures_lifetime.hpp"

#include <imgui.h>
#include <spdlog/spdlog.h>

#include <SFML/Graphics/Image.hpp>
#include <SFML/System/Vector2.hpp>
#include <array>

#include "globals/textures.hpp"

void TexturesLifetime::onStartup() {
    g::textures = std::make_unique<g::Textures>();
    spdlog::debug("Loading all textures ...");

    {
        static constexpr auto DATA = std::to_array<unsigned char>({
#embed "assets/images/lightning-bolt-icon-white.png"
        });
        loadTextureFromMemory(g::textures->lightningBoltIconWhite, DATA.data(), DATA.size(),
                              "lightning-bolt-icon-white.png");
    }

    {
        static constexpr auto DATA = std::to_array<unsigned char>({
#embed "assets/images/signal-tower-icon-white.png"
        });
        loadTextureFromMemory(g::textures->signalTowerIconWhite, DATA.data(), DATA.size(),
                              "signal-tower-icon-white.png");
    }

    {
        static constexpr auto DATA = std::to_array<unsigned char>({
#embed "assets/images/plus-icon-white.png"
        });
        loadTextureFromMemory(g::textures->plusIconWhite, DATA.data(), DATA.size(),
                              "plus-icon-white.png");
    }

    {
        static constexpr auto DATA = std::to_array<unsigned char>({
#embed "assets/images/plus-icon-muted.png"
        });
        loadTextureFromMemory(g::textures->plusIconMuted, DATA.data(), DATA.size(),
                              "plus-icon-muted.png");
    }

    {
        static constexpr auto DATA = std::to_array<unsigned char>({
#embed "assets/images/cross-icon-white.png"
        });
        loadTextureFromMemory(g::textures->crossIconWhite, DATA.data(), DATA.size(),
                              "cross-icon-white.png");
    }

    {
        static constexpr auto DATA = std::to_array<unsigned char>({
#embed "assets/images/cross-icon-muted.png"
        });
        loadTextureFromMemory(g::textures->crossIconMuted, DATA.data(), DATA.size(),
                              "cross-icon-muted.png");
    }

    {
        static constexpr auto DATA = std::to_array<unsigned char>({
#embed "assets/images/list-icon-muted.png"
        });
        loadTextureFromMemory(g::textures->listIconMuted, DATA.data(), DATA.size(),
                              "list-icon-muted.png");
    }

    spdlog::debug("Loaded all textures");
}

void TexturesLifetime::onShutdown() { g::textures.reset(); }

void TexturesLifetime::loadTextureFromMemory(sf::Texture& texture, const void* data, size_t size,
                                             std::string_view debugName) {
    if (!texture.loadFromMemory(data, size)) {
        spdlog::error("Failed to load texture '{}': error when loading from memory", debugName);
        return;
    }

    if (!smoothenTexture(texture)) {
        spdlog::error("Failed to generate mipmap when loading texture '{}'", debugName);
    }
}

bool TexturesLifetime::smoothenTexture(sf::Texture& texture) {
    texture.setSmooth(true);
    return texture.generateMipmap();
}

#pragma clang diagnostic pop
