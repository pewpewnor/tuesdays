#pragma once

#include <imgui.h>

#include <SFML/Graphics/Texture.hpp>
#include <memory>

namespace g {

struct Textures {
    sf::Texture lightningBoltIconWhite;
    sf::Texture signalTowerIconWhite;
    sf::Texture plusIconWhite;
    sf::Texture plusIconMuted;
    sf::Texture crossIconWhite;
    sf::Texture crossIconMuted;
    sf::Texture listIconMuted;
};

inline std::unique_ptr<g::Textures> textures;

}
