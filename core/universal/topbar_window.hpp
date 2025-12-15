#pragma once

#include <memory>

#include "navbar_window.hpp"

class TopbarWindow : public commons::WindowRenderStep {
public:
    ImVec2 windowPos;
    ImVec2 windowSize;

    TopbarWindow(const std::shared_ptr<NavbarWindow>& navbar);

    bool begin() override;

    void renderContent() override;

private:
    std::shared_ptr<NavbarWindow> navbar_;
};
