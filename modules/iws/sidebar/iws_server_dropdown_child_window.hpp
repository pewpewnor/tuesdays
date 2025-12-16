#pragma once

#include <imgui.h>

#include <memory>

#include "commons/child_window_part.hpp"
#include "iws/states/server.hpp"

class IwsServerDropdownChildWindow : public commons::ChildWindowPart {
public:
    bool isOpen = false;
    float windowSizeX = 0;

    IwsServerDropdownChildWindow(const std::shared_ptr<iws::Server>& server);

private:
    std::shared_ptr<iws::Server> server_;
    bool wasHovered_ = false;

    bool begin() override;

    void renderContent() override;
};
