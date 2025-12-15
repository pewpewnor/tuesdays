#pragma once

#include <memory>

#include "commons/child_window_part.hpp"
#include "iws/sidebar/iws_server_dropdown_child_window.hpp"
#include "iws/states/server.hpp"

class IwsServerChildWindow : public commons::ChildWindowPart {
public:
    std::shared_ptr<iws::Server> server;

    IwsServerChildWindow(const std::shared_ptr<iws::Server>& server);

private:
    IwsServerDropdownChildWindow serverDropdownChildWindow_;

    bool begin() override;

    void renderContent() override;
};
