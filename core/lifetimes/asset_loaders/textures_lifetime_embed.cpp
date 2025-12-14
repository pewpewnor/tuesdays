#include <array>

#include "globals/textures.hpp"
#include "textures_lifetime.hpp"
#include "utils/macros.hpp"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"

void TexturesLifetime::loadTextures() {
    static constexpr auto LIGHTNING_BOLT_ICON_WHITE = std::to_array<uint8_t>({
#embed "assets/images/lightning-bolt-icon-white.png"
    });
    loadTextureFromMemory(g::textures->lightningBoltIconWhite, LIGHTNING_BOLT_ICON_WHITE.data(),
                          LIGHTNING_BOLT_ICON_WHITE.size(), NAME_OF(LIGHTNING_BOLT_ICON_WHITE));

    static constexpr auto SIGNAL_TOWER_ICON_WHITE = std::to_array<uint8_t>({
#embed "assets/images/signal-tower-icon-white.png"
    });
    loadTextureFromMemory(g::textures->signalTowerIconWhite, SIGNAL_TOWER_ICON_WHITE.data(),
                          SIGNAL_TOWER_ICON_WHITE.size(), NAME_OF(SIGNAL_TOWER_ICON_WHITE));

    static constexpr auto PLUS_ICON_WHITE = std::to_array<uint8_t>({
#embed "assets/images/plus-icon-white.png"
    });
    loadTextureFromMemory(g::textures->plusIconWhite, PLUS_ICON_WHITE.data(),
                          PLUS_ICON_WHITE.size(), NAME_OF(PLUS_ICON_WHITE));

    static constexpr auto PLUS_ICON_GRAY = std::to_array<uint8_t>({
#embed "assets/images/plus-icon-gray.png"
    });
    loadTextureFromMemory(g::textures->plusIconGray, PLUS_ICON_GRAY.data(), PLUS_ICON_GRAY.size(),
                          NAME_OF(PLUS_ICON_GRAY));

    static constexpr auto CROSS_ICON_WHITE = std::to_array<uint8_t>({
#embed "assets/images/cross-icon-white.png"
    });
    loadTextureFromMemory(g::textures->crossIconWhite, CROSS_ICON_WHITE.data(),
                          CROSS_ICON_WHITE.size(), NAME_OF(CROSS_ICON_WHITE));

    static constexpr auto CROSS_ICON_GRAY = std::to_array<uint8_t>({
#embed "assets/images/cross-icon-gray.png"
    });
    loadTextureFromMemory(g::textures->crossIconGray, CROSS_ICON_GRAY.data(),
                          CROSS_ICON_GRAY.size(), NAME_OF(CROSS_ICON_GRAY));

    static constexpr auto LIST_ICON_GRAY = std::to_array<uint8_t>({
#embed "assets/images/list-icon-gray.png"
    });
    loadTextureFromMemory(g::textures->listIconGray, LIST_ICON_GRAY.data(), LIST_ICON_GRAY.size(),
                          NAME_OF(LIST_ICON_GRAY));

    static constexpr auto CHEVRON_DOWN_ICON_GRAY = std::to_array<uint8_t>({
#embed "assets/images/chevron-down-icon-gray.png"
    });
    loadTextureFromMemory(g::textures->chevronDownIconGray, CHEVRON_DOWN_ICON_GRAY.data(),
                          CHEVRON_DOWN_ICON_GRAY.size(), NAME_OF(CHEVRON_DOWN_ICON_GRAY));

    static constexpr auto CHEVRON_RIGHT_ICON_GRAY = std::to_array<uint8_t>({
#embed "assets/images/chevron-right-icon-gray.png"
    });
    loadTextureFromMemory(g::textures->chevronDownIconGray, CHEVRON_RIGHT_ICON_GRAY.data(),
                          CHEVRON_RIGHT_ICON_GRAY.size(), NAME_OF(CHEVRON_RIGHT_ICON_GRAY));
}

#pragma clang diagnostic pop
