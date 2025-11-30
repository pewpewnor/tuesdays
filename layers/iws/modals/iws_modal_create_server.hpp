#pragma once

#include "commons/window_part.hpp"

class IwsModalCreateServer : public WindowPart {
private:
    bool begin() override;

    void renderContent() override;

    void end() override;
};
