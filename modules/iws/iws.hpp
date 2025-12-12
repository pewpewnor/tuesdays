#pragma once

#include "engine/steps/group_step.hpp"
#include "universal/navbar_window.hpp"
#include "universal/topbar_window.hpp"

class Iws : public engine::GroupStep {
public:
    Iws(const std::shared_ptr<NavbarWindow>& navbar, const std::shared_ptr<TopbarWindow>& topbar);

    bool shouldRender() override;
};
