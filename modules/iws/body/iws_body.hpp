#pragma once

#include "iws/sidebar/iws_sidebar.hpp"
#include "universal/topbar.hpp"

class IwsBody : public engine::RenderWindowStep {
public:
    IwsBody(const std::shared_ptr<Topbar>& topbar, const std::shared_ptr<IwsSidebar>& acmSidebar);

private:
    std::shared_ptr<Topbar> topbar_;
    std::shared_ptr<IwsSidebar> acmSidebar_;

    bool beginWindow() override;

    void renderWindowContent() override;
};
