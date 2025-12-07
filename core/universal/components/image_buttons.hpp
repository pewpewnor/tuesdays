#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <string>

namespace components {

bool navbarAppImageButton(const std::string& label, bool isActive, const sf::Texture& icon);

bool crossIconButton(const std::string& label, float size = 12);

bool plusIconButton(const std::string& label, float size = 12);

}
