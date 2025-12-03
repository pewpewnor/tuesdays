#pragma once

#include "engine/steps/shutdown_step.hpp"
#include "engine/steps/startup_step.hpp"

class TasksLifetime : public engine::StartupStep, public engine::ShutdownStep {
public:
    void onStartup() override;

    void onShutdown() override;
};
