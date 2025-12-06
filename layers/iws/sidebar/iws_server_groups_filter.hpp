#pragma once

#include <imgui.h>

#include <memory>

#include "iws/modals/iws_create_server_group_modal.hpp"
#include "iws/sidebar/iws_sidebar.hpp"

class IwsServerGroupsFilter : public engine::RenderWindowStep {
public:
    static constexpr ImVec2 WINDOW_PADDING = {16, 16};

    IwsServerGroupsFilter(const std::shared_ptr<IwsSidebar>& iwsSidebar);

private:
    std::unique_ptr<IwsCreateServerGroupModal> iwsCreateServerGroupModal_;
    std::shared_ptr<IwsSidebar> iwsSidebar_;

    bool beginWindow() override;

    void renderWindowContent() override;
};
