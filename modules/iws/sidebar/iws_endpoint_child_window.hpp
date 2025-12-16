#pragma once

#include <memory>

#include "commons/child_window_part.hpp"
#include "iws/states/endpoint.hpp"

class IwsEndpointChildWindow : public commons::ChildWindowPart {
public:
    std::shared_ptr<iws::Endpoint> endpoint;

    IwsEndpointChildWindow(const std::shared_ptr<iws::Endpoint>& endpoint);

private:
    bool begin() override;

    void renderContent() override;
};
