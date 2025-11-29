#pragma once

#include <imgui.h>

#include <memory>

#include "engine/template_steps/render_window_step.hpp"
#include "universal/navbar.hpp"
#include "universal/topbar.hpp"

class IwsSidebar : public engine::RenderWindowStep {
public:
    IwsSidebar(const std::shared_ptr<Navbar>& navbar, const std::shared_ptr<Topbar>& topbar);

    bool shouldRender() override;

    bool beginWindow() override;

    void renderWindowContent() override;

private:
    std::shared_ptr<Navbar> navbar_;
    std::shared_ptr<Topbar> topbar_;
};
