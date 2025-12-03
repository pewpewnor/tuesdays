#pragma once

#include "engine/steps/group_step.hpp"
#include "universal/navbar.hpp"
#include "universal/topbar.hpp"

class Iws : public engine::GroupStep {
public:
    Iws(const std::shared_ptr<Navbar>& navbar, const std::shared_ptr<Topbar>& topbar);

    bool shouldRender() override;
};
