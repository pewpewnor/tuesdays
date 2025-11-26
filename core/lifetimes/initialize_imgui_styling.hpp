#pragma once

#include "engine/startup_step.hpp"

class InitializeImguiStyling : public engine::StartupStep {
public:
    void onStartup() override;
};
