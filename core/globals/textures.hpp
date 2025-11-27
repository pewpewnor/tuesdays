#pragma once

#include <imgui.h>

#include <SFML/Graphics/Texture.hpp>
#include <memory>

namespace g {

class Textures {
public:
    sf::Texture lightningBoltIconBlack;
    sf::Texture lightningBoltIconWhite;
    sf::Texture radarIconWhite;
    sf::Texture radarIconBlack;
};

inline std::unique_ptr<g::Textures> textures;

}
