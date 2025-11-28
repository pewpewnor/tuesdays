#pragma once

#include <memory>

#include "engine/template_steps/render_window_step.hpp"
#include "layers/topbar.hpp"
#include "utils/imgui/bring_window_to_front_once.hpp"

class AcmMenubar : public engine::RenderWindowStep {
public:
    ImVec2 windowPos;
    ImVec2 windowSize;

    AcmMenubar(const std::shared_ptr<Topbar>& topbar);

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
