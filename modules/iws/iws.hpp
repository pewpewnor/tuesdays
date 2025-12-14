#pragma once

#include "engine/steps/group_step.hpp"
#include "universal/navbar_window.hpp"
#include "universal/topbar_window.hpp"

class Iws : public engine::GroupStep {
public:
    Iws(const std::shared_ptr<NavbarWindow>& navbarWindow,
        const std::shared_ptr<TopbarWindow>& topbarWindow);

    bool shouldRender() override;

private:
    std::shared_ptr<NavbarWindow> navbarWindow_;
    std::shared_ptr<TopbarWindow> topbarWindow_;

    void addRenderSteps();
};
