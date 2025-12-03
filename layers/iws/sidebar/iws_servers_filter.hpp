#pragma once

#include <imgui.h>

#include <memory>

#include "engine/steps/startup_step.hpp"
#include "iws/modals/iws_modal_create_server.hpp"
#include "iws/sidebar/iws_sidebar.hpp"

class IwsServersFilter : public engine::RenderWindowStep, public engine::StartupStep {
public:
    IwsServersFilter(const std::shared_ptr<IwsSidebar>& iwsSidebar);

    void onStartup() override;

    bool beginWindow() override;

    void renderWindowContent() override;

private:
    IwsModalCreateServer createServerModal_;
    std::shared_ptr<IwsSidebar> iwsSidebar_;
};
