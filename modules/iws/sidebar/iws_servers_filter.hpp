#pragma once

#include <imgui.h>

#include <memory>

#include "iws/sidebar/iws_sidebar.hpp"

class IwsServersFilter : public RenderWindowStep {
public:
    IwsServersFilter(const std::shared_ptr<IwsSidebar>& iwsSidebar);

    bool shouldRender() override;

    bool beginWindow() override;

    void renderWindowContent() override;

private:
    std::shared_ptr<IwsSidebar> iwsSidebar_;
};
