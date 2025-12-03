#pragma once

#include <memory>
#include <vector>

#include "render_step.hpp"
#include "shutdown_step.hpp"
#include "startup_step.hpp"

namespace engine {

class GroupStep : public virtual engine::StartupStep,
                  public virtual engine::RenderStep,
                  public virtual engine::ShutdownStep {
public:
    GroupStep() = default;
    GroupStep(const GroupStep&) = default;
    GroupStep(GroupStep&&) = delete;
    GroupStep& operator=(const GroupStep&) = default;
    GroupStep& operator=(GroupStep&&) = delete;
    ~GroupStep() override = default;

    void onStartup() override;

    void onRender() override;

    void onShutdown() override;

protected:
    std::vector<std::shared_ptr<engine::StartupStep>> startupSteps;
    std::vector<std::shared_ptr<engine::RenderStep>> renderSteps;
    std::vector<std::shared_ptr<engine::ShutdownStep>> shutdownSteps;
};

}
