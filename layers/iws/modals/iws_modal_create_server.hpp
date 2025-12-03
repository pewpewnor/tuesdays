#pragma once

#include <array>

#include "commons/display_part.hpp"

class IwsModalCreateServer : public commons::DisplayPart {
public:
    void resetAll();

private:
    std::array<char, 255> serverNameBuffer_;
    bool violatedServerNameRequired_;

    bool begin() override;

    void displayContent() override;

    void endOfDisplay() override;

    void resetValidations();
};
