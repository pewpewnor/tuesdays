#pragma once

#include "iws/sidebar/iws_sidebar_window.hpp"
#include "universal/topbar_window.hpp"

class IwsBodyWindow : public commons::WindowRenderStep {
public:
    IwsBodyWindow(const std::shared_ptr<TopbarWindow>& topbar,
                  const std::shared_ptr<IwsSidebarWindow>& acmSidebar);

private:
    std::shared_ptr<TopbarWindow> topbar_;
    std::shared_ptr<IwsSidebarWindow> acmSidebar_;

    bool beginWindow() override;

    void renderWindowContent() override;
};
