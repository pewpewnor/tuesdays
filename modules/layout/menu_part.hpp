#pragma once

#include <string>

#include "commons/display_part.hpp"

namespace components {

class MenuPart : public virtual commons::DisplayPart {
public:
    MenuPart(const std::string& label);
    MenuPart(const MenuPart&) = default;
    MenuPart(MenuPart&&) = delete;
    MenuPart& operator=(const MenuPart&) = delete;
    MenuPart& operator=(MenuPart&&) = delete;
    ~MenuPart() override = default;

private:
    bool wasHovered_ = false;
    std::string label_;

    bool begin() override;

    void endOfDisplay() override;
};

}
