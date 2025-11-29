#pragma once

#include <SFML/Graphics/Texture.hpp>

namespace components {

bool navbarAppImageButton(const char* label, bool isActive, const sf::Texture& icon);

bool beginMenubarMenu(const char* label);

}
