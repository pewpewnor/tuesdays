#pragma once

#include <imgui.h>

#include <memory>

#include "universal/navbar.hpp"
#include "universal/topbar.hpp"

class IwsSidebar : public engine::RenderWindowStep {
public:
    IwsSidebar(const std::shared_ptr<Navbar>& navbar, const std::shared_ptr<Topbar>& topbar);

private:
    std::shared_ptr<Navbar> navbar_;
    std::shared_ptr<Topbar> topbar_;

    bool beginWindow() override;
};
