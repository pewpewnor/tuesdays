#pragma once

#include <string>

#include "commons/display_part.hpp"

namespace components {

class Menu : public virtual commons::DisplayPart {
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

    void endOfDisplay() override;
};

}
