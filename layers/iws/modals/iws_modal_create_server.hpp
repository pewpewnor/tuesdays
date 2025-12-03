#pragma once

#include <array>

#include "commons/display_part.hpp"

class IwsModalCreateServer : public commons::DisplayPart {
private:
    bool violatedServerNameRequired_ = false;
    std::array<char, 255> serverNameBuffer_{'\0'};

    bool begin() override;

    void displayContent() override;

    void endOfDisplay() override;

    void resetAll();

    void resetValidations();
};
