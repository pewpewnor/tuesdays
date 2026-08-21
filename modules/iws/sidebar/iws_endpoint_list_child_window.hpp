#pragma once

#include <vector>

#include "commons/child_window_part.hpp"
#include "iws/sidebar/iws_endpoint_child_window.hpp"

class IwsEndpointListChildWindow : public commons::ChildWindowPart {
public:
    std::vector<IwsEndpointChildWindow> endpointChildWindows;

private:
    bool begin() override;

    void renderContent() override;
};
