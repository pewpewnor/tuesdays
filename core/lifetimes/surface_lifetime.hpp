#pragma once

#include "engine/steps/shutdown_step.hpp"
#include "engine/steps/startup_step.hpp"

class SurfaceLifetime : public engine::StartupStep, public engine::ShutdownStep {
public:
    static constexpr int WIDTH = 1280;
    static constexpr int HEIGHT = 720;

    void onStartup() override;

    void onShutdown() override;

private:
    bool windowInitialized_ = false;
    bool imguiInitialized_ = false;
};
