#pragma once

#include <memory>

#include "navbar_window.hpp"

class TopbarWindow : public commons::WindowRenderStep {
public:
    TopbarWindow(const std::shared_ptr<NavbarWindow>& navbar);

    bool beginWindow() override;

    void renderWindowContent() override;

private:
    std::shared_ptr<NavbarWindow> navbar_;
};
