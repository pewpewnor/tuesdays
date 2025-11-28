#pragma once

#include "acm_sidebar.hpp"
#include "engine/template_steps/render_window_step.hpp"
#include "universal/topbar.hpp"

class AcmBody : public engine::RenderWindowStep {
public:
    AcmBody(const std::shared_ptr<Topbar>& topbar, const std::shared_ptr<AcmSidebar>& acmSidebar);

    bool shouldRender() override;

    bool beginWindow() override;

    void renderWindowContent() override;

private:
    std::shared_ptr<Topbar> topbar_;
    std::shared_ptr<AcmSidebar> acmSidebar_;
};
