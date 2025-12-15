#pragma once

#include "iws/sidebar/iws_sidebar_window.hpp"
#include "universal/topbar_window.hpp"

class IwsBodyWindow : public commons::WindowRenderStep {
public:
    IwsBodyWindow(const std::shared_ptr<TopbarWindow>& topbar,
                  const std::shared_ptr<IwsSidebarWindow>& iwsSidebarWindow);

private:
    std::shared_ptr<TopbarWindow> topbar_;
    std::shared_ptr<IwsSidebarWindow> iwsSidebarWindow_;

    bool begin() override;

    void renderContent() override;
};
