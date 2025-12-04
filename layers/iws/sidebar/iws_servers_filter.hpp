#pragma once

#include <imgui.h>

#include <memory>

#include "iws/modals/iws_create_server_modal.hpp"
#include "iws/sidebar/iws_sidebar.hpp"

class IwsServersFilter : public engine::RenderWindowStep {
public:
    IwsServersFilter(const std::shared_ptr<IwsSidebar>& iwsSidebar);

    bool beginWindow() override;

    void renderWindowContent() override;

private:
    std::unique_ptr<IwsCreateServerModal> createServerModal_;
    std::shared_ptr<IwsSidebar> iwsSidebar_;
};
