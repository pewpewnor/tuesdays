#pragma once

#include <memory>

#include "commons/child_window_part.hpp"
#include "iws/states/server.hpp"

class IwsServerDropdownChildWindow : public commons::ChildWindowPart {
public:
    IwsServerDropdownChildWindow(const std::shared_ptr<iws::Server>& server);

private:
    std::shared_ptr<iws::Server> server_;
    bool isOpen_ = false;
    bool wasHovered_ = false;

    bool beginChildWindow() override;

    void displayChildWindowContent() override;
};
