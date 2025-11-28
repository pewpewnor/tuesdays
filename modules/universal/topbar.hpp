#pragma once

#include <memory>

#include "engine/template_steps/render_window_step.hpp"
#include "navbar.hpp"

class Topbar : public engine::RenderWindowStep {
public:
    Topbar(const std::shared_ptr<Navbar>& navbar);

    bool beginWindow() override;

    void renderWindowContent() override;

private:
    std::shared_ptr<Navbar> navbar_;
};
