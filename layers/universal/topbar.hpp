#pragma once

#include <memory>

#include "navbar.hpp"

class Topbar : public RenderWindowStep {
public:
    Topbar(const std::shared_ptr<Navbar>& navbar);

    bool beginWindow() override;

    void renderWindowContent() override;

private:
    std::shared_ptr<Navbar> navbar_;
};
