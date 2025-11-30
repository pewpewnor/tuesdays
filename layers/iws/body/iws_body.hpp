#pragma once

#include "iws/sidebar/iws_sidebar.hpp"
#include "universal/topbar.hpp"

class IwsBody : public RenderWindowStep {
public:
    IwsBody(const std::shared_ptr<Topbar>& topbar, const std::shared_ptr<IwsSidebar>& acmSidebar);

    bool beginWindow() override;

    void renderWindowContent() override;

private:
    std::shared_ptr<Topbar> topbar_;
    std::shared_ptr<IwsSidebar> acmSidebar_;
};
