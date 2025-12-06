#include <array>

#include "globals/textures.hpp"
#include "textures_lifetime.hpp"
#include "utils/macros.hpp"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"

void TexturesLifetime::loadTextures() {
    static constexpr auto LIGHTNING_ICON = std::to_array<unsigned char>({
#embed "assets/images/lightning-bolt-icon-white.png"
    });
    loadTextureFromMemory(g::textures->lightningBoltIconWhite, LIGHTNING_ICON.data(),
                          LIGHTNING_ICON.size(), NAME_OF(LIGHTNING_ICON));

    static constexpr auto SIGNAL_TOWER_ICON = std::to_array<unsigned char>({
#embed "assets/images/signal-tower-icon-white.png"
    });
    loadTextureFromMemory(g::textures->signalTowerIconWhite, SIGNAL_TOWER_ICON.data(),
                          SIGNAL_TOWER_ICON.size(), NAME_OF(SIGNAL_TOWER_ICON));

    static constexpr auto PLUS_ICON_WHITE = std::to_array<unsigned char>({
#embed "assets/images/plus-icon-white.png"
    });
    loadTextureFromMemory(g::textures->plusIconWhite, PLUS_ICON_WHITE.data(),
                          PLUS_ICON_WHITE.size(), NAME_OF(PLUS_ICON_WHITE));

    static constexpr auto PLUS_ICON_MUTED = std::to_array<unsigned char>({
#embed "assets/images/plus-icon-muted.png"
    });
    loadTextureFromMemory(g::textures->plusIconMuted, PLUS_ICON_MUTED.data(),
                          PLUS_ICON_MUTED.size(), NAME_OF(PLUS_ICON_MUTED));

    static constexpr auto CROSS_ICON_WHITE = std::to_array<unsigned char>({
#embed "assets/images/cross-icon-white.png"
    });
    loadTextureFromMemory(g::textures->crossIconWhite, CROSS_ICON_WHITE.data(),
                          CROSS_ICON_WHITE.size(), NAME_OF(CROSS_ICON_WHITE));

    static constexpr auto CROSS_ICON_MUTED = std::to_array<unsigned char>({
#embed "assets/images/cross-icon-muted.png"
    });
    loadTextureFromMemory(g::textures->crossIconMuted, CROSS_ICON_MUTED.data(),
                          CROSS_ICON_MUTED.size(), NAME_OF(CROSS_ICON_MUTED));

    static constexpr auto LIST_ICON_MUTED = std::to_array<unsigned char>({
#embed "assets/images/list-icon-muted.png"
    });
    loadTextureFromMemory(g::textures->listIconMuted, LIST_ICON_MUTED.data(),
                          LIST_ICON_MUTED.size(), NAME_OF(LIST_ICON_MUTED));
}

#pragma clang diagnostic pop
