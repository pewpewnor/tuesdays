#pragma once

#include <string>

#include "commons/child_window_part.hpp"

class IwsServerDropdownChildWindow : public commons::ChildWindowPart {
public:
    IwsServerDropdownChildWindow(const std::string& serverName);

private:
    std::string serverName_;
    bool isOpen_ = false;
    bool wasHovered_ = false;

    bool beginChildWindow() override;

    void displayChildWindowContent() override;
};
