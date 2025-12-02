#pragma once

#include <array>

#include "commons/window_part.hpp"

class IwsModalCreateServer : public WindowPart {
private:
    bool violatedServerNameRequired_ = false;
    std::array<char, 255> serverNameBuffer_{'\0'};

    bool begin() override;

    void displayContent() override;

    void end() override;

    void resetAll();

    void resetValidations();
};
