#pragma once

#include <array>

#include "commons/display_part.hpp"

class IwsCreateServerGroupModal : public commons::DisplayPart {
private:
    std::array<char, 257> serverNameBuffer_ = {'\0'};
    bool violatedServerNameRequired_ = false;

    bool begin() override;

    void displayContent() override;

    void endOfDisplay() override;

    void resetValidations();

    static void closePopup();
};
