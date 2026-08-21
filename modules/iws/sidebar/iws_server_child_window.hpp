#pragma once

#include <memory>

#include "commons/child_window_part.hpp"
#include "iws/states/server.hpp"
#include "iws_endpoint_list_child_window.hpp"
#include "iws_server_left_dropdown_child_window.hpp"

class IwsServerChildWindow : public commons::ChildWindowPart {
public:
    IwsServerChildWindow(const std::shared_ptr<iws::Server>& server);

private:
    IwsServerLeftDropdownChildWindow serverLeftDropdownChildWindow_;
    IwsEndpointListChildWindow endpointListChildWindow_;
    std::shared_ptr<iws::Server> server_;

    bool begin() override;

    void renderContent() override;
};
