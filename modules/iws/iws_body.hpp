#pragma once

#include "engine/template_steps/render_window_step.hpp"
#include "iws_sidebar.hpp"
#include "universal/topbar.hpp"

class IwsBody : public engine::RenderWindowStep {
public:
    IwsBody(const std::shared_ptr<Topbar>& topbar, const std::shared_ptr<IwsSidebar>& acmSidebar);

    bool shouldRender() override;

    bool beginWindow() override;

    void renderWindowContent() override;

private:
    std::shared_ptr<Topbar> topbar_;
    std::shared_ptr<IwsSidebar> acmSidebar_;
};
