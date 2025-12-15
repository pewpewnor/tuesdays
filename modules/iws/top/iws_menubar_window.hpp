#pragma once

#include <memory>

#include "iws/top/iws_menu_parts.hpp"
#include "universal/topbar_window.hpp"

class IwsMenubarWindow : public commons::WindowRenderStep {
public:
    IwsMenubarWindow(const std::shared_ptr<TopbarWindow>& topbarWindow);

private:
    IwsMenuPartFile fileMenuPart_;
    IwsMenuPartEdit editMenuPart_;
    IwsMenuPartView viewMenuPart_;
    std::shared_ptr<TopbarWindow> topbarWindow_;

    bool beginWindow() override;

    void renderWindowContent() override;
};
