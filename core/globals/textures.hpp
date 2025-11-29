#pragma once

#include <imgui.h>

#include <SFML/Graphics/Texture.hpp>
#include <memory>

namespace g {

class Textures {
public:
    sf::Texture lightningBoltIconWhite;
    sf::Texture signalTowerIconWhite;
    sf::Texture plusIconMuted;
};

inline std::unique_ptr<g::Textures> textures;

}
