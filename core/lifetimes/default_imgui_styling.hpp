#pragma once

#include "engine/startup_step.hpp"

class DefaultImguiStyling : public engine::StartupStep {
public:
    void onStartup() override;
};
