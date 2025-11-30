#pragma once

#include "commons/steps/render_group.hpp"
#include "universal/navbar.hpp"
#include "universal/topbar.hpp"

class Iws : public RenderGroup {
public:
    Iws(const std::shared_ptr<Navbar>& navbar, const std::shared_ptr<Topbar>& topbar);

    bool shouldRender() override;
};
