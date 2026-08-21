#pragma once

#include <memory>

#include "commons/child_window_part.hpp"
#include "iws/states/endpoint.hpp"

class IwsEndpointChildWindow : public commons::ChildWindowPart {
public:
    IwsEndpointChildWindow(const std::shared_ptr<iws::Endpoint>& endpoint);

private:
    std::shared_ptr<iws::Endpoint> endpoint_;

    bool begin() override;

    void renderContent() override;
};
