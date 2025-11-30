#pragma once

#include <imgui.h>

#include <memory>

#include "universal/navbar.hpp"
#include "universal/topbar.hpp"

class IwsSidebar : public RenderWindowStep {
public:
    IwsSidebar(const std::shared_ptr<Navbar>& navbar, const std::shared_ptr<Topbar>& topbar);

    bool beginWindow() override;

private:
    std::shared_ptr<Navbar> navbar_;
    std::shared_ptr<Topbar> topbar_;
};
