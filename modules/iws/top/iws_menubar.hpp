#pragma once

#include <memory>

#include "universal/topbar.hpp"
#include "utils/imgui/bring_window_to_front_once.hpp"

class IwsMenubar : public RenderWindowStep {
public:
    IwsMenubar(const std::shared_ptr<Topbar>& topbar);

    bool shouldRender() override;

    bool beginWindow() override;

    void renderWindowContent() override;

private:
    std::shared_ptr<Topbar> topbar_;
    BringWindowToFrontOnce bringWindowToFrontOnce_;

    static void renderFileMenu();

    static void renderEditMenu();

    static void renderViewMenu();
};
