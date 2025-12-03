#pragma once

#include <imgui.h>

#include <memory>

#include "iws/modals/iws_modal_create_server.hpp"
#include "iws/sidebar/iws_sidebar.hpp"

class IwsServersFilter : public commons::RenderWindowStep {
public:
    IwsServersFilter(const std::shared_ptr<IwsSidebar>& iwsSidebar);

    bool beginWindow() override;

    void renderWindowContent() override;

private:
    IwsModalCreateServer createServerModal_;
    std::shared_ptr<IwsSidebar> iwsSidebar_;
};
