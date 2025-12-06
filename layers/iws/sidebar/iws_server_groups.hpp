#pragma once

#include "engine/steps/render_window_step.hpp"
#include "iws/sidebar/iws_server_groups_filter.hpp"

class IwsServerGroups : public engine::RenderWindowStep {
public:
    IwsServerGroups(const std::shared_ptr<IwsServerGroupsFilter>& iwsServersFilter);

private:
    std::shared_ptr<IwsServerGroupsFilter> iwsServersFilter_;

    bool beginWindow() override;

    void renderWindowContent() override;
};
