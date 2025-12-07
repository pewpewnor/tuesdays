#pragma once

#include <imgui.h>

#include <memory>

#include "iws/modals/iws_create_server_group_modal.hpp"
#include "universal/navbar.hpp"
#include "universal/topbar.hpp"

class IwsSidebar : public engine::RenderWindowStep {
public:
    IwsSidebar(const std::shared_ptr<Navbar>& navbar, const std::shared_ptr<Topbar>& topbar);

private:
    std::shared_ptr<Navbar> navbar_;
    std::shared_ptr<Topbar> topbar_;
    std::unique_ptr<IwsCreateServerGroupModal> iwsCreateServerGroupModal_;

    bool beginWindow() override;

    void renderWindowContent() override;
};
