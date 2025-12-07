#pragma once

#include <string>

#include "commons/child_window_part.hpp"

class IwsServerGroupDropdown : public commons::ChildWindowPart {
public:
    IwsServerGroupDropdown(const std::string& serverGroupName);

private:
    std::string serverGroupName_;
    bool wasHovered_ = false;

    bool beginChildWindow() override;

    void displayChildWindowContent() override;
};
