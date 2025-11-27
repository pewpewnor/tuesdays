#pragma once

#include "engine/shutdown_step.hpp"
#include "engine/startup_step.hpp"

class SurfaceLifetime : public engine::StartupStep, public engine::ShutdownStep {
public:
    int width = 1280;
    int height = 720;

    void onStartup() override;

    void onShutdown() override;

private:
    bool windowInitialized_ = false;
    bool imguiInitialized_ = false;
};
