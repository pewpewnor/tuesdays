#pragma once

#include "engine/steps/startup_step.hpp"

class DefaultImguiStyling : public engine::StartupStep {
public:
    void onStartup() override;
};
