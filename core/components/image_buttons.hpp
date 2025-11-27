#pragma once

#include <SFML/Graphics/Texture.hpp>

namespace components {

bool navbarAppImageButton(const char* id, bool isActive, const sf::Texture& on,
                          const sf::Texture& off);

}
