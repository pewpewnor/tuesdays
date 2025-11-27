#pragma once

#include <imgui.h>

#include <memory>

#include "engine/render_step.hpp"
#include "navbar.hpp"

class AcmWindow : public engine::RenderStep {
public:
    AcmWindow(const std::shared_ptr<Navbar>& suiteSidebar);

    bool shouldRender() override;

    void onRender() override;

private:
    std::shared_ptr<Navbar> suiteSidebar_;
};
