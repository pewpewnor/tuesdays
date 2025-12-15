#pragma once

#include <imgui.h>

#include <memory>

#include "iws/modals/iws_create_server_modal_part.hpp"
#include "universal/navbar_window.hpp"
#include "universal/topbar_window.hpp"

class IwsSidebarWindow : public commons::WindowRenderStep {
public:
    IwsSidebarWindow(const std::shared_ptr<NavbarWindow>& navbarWindow,
                     const std::shared_ptr<TopbarWindow>& topbarWindow);

private:
    std::shared_ptr<NavbarWindow> navbarWindow_;
    std::shared_ptr<TopbarWindow> topbarWindow_;
    std::unique_ptr<IwsCreateServerModalPart> iwsCreateServerModal_;

    bool beginWindow() override;

    void renderWindowContent() override;
};
