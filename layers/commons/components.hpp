#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <string>

#include "window_part.hpp"

namespace components {

bool navbarAppImageButton(const std::string& label, bool isActive, const sf::Texture& icon);

bool crossIconButton(const std::string& label, float size = 12);

bool plusIconButton(const std::string& label, float size = 12);

class Menu : public virtual WindowPart {
public:
    Menu(const std::string& label);
    Menu(const Menu&) = default;
    Menu(Menu&&) = delete;
    Menu& operator=(const Menu&) = delete;
    Menu& operator=(Menu&&) = delete;
    ~Menu() override = default;

private:
    std::string label_;

    bool begin() override;

    void end() override;
};

}
