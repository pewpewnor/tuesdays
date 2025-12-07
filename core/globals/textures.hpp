#pragma once

#include <imgui.h>

#include <SFML/Graphics/Texture.hpp>
#include <memory>

namespace g {

struct Textures {
    sf::Texture lightningBoltIconWhite;
    sf::Texture signalTowerIconWhite;
    sf::Texture plusIconWhite;
    sf::Texture plusIconGray;
    sf::Texture crossIconWhite;
    sf::Texture crossIconGray;
    sf::Texture listIconGray;
    sf::Texture chevronDownIconGray;
    sf::Texture chevronRightIconGray;
};

inline std::unique_ptr<g::Textures> textures;

}
