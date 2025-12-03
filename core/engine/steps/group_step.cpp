#include "group_step.hpp"

#include <ranges>

void engine::GroupStep::onStartup() {
    for (const std::shared_ptr<engine::StartupStep>& startupStep : startupSteps) {
        startupStep->onStartup();
    }
}

void engine::GroupStep::onRender() {
    for (const std::shared_ptr<engine::RenderStep>& renderStep : renderSteps) {
        if (renderStep->shouldRender()) {
            renderStep->onRender();
        }
    }
}

void engine::GroupStep::onShutdown() {
    for (const std::shared_ptr<engine::ShutdownStep>& shutdownStep :
         std::ranges::reverse_view(shutdownSteps)) {
        shutdownStep->onShutdown();
    }
}
