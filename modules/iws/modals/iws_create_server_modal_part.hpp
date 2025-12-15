#pragma once

#include <array>

#include "commons/popup_window_part.hpp"

class IwsCreateServerModalPart : public commons::PopupWindowPart {
private:
    std::array<char, 257> serverNameBuffer_ = {'\0'};
    bool violatedServerNameRequired_ = false;

    bool begin() override;

    void renderContent() override;

    void resetValidations();

    static void closePopup();
};
