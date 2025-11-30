#pragma once

#include <memory>

#include "iws/top/iws_menus.hpp"
#include "universal/topbar.hpp"

class IwsMenubar : public RenderWindowStep {
public:
    IwsMenubar(const std::shared_ptr<Topbar>& topbar);

    bool beginWindow() override;

    void renderWindowContent() override;

private:
    IwsMenuFile fileMenu_;
    IwsMenuEdit editMenu_;
    IwsMenuView viewMenu_;

    std::shared_ptr<Topbar> topbar_;
};
