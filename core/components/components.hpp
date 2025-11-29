#pragma once

#include <SFML/Graphics/Texture.hpp>

namespace components {

bool navbarAppImageButton(const char* id, bool isActive, const sf::Texture& light,
                          const sf::Texture& dark);

bool beginMenubarMenu(const char* id);

}
