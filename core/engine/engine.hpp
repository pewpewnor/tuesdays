#pragma once

#include <imgui.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <atomic>
#include <condition_variable>
#include <mutex>
#include <vector>

#include "render_step.hpp"
#include "shutdown_step.hpp"
#include "startup_step.hpp"

namespace engine {

class Engine {
public:
    std::shared_ptr<sf::RenderWindow> window;
    std::atomic<bool> renderOnIdle = false;

    void runContinously();

    void pushStartupStep(const std::shared_ptr<engine::StartupStep>& step);

    void extendStartupSteps(const std::vector<std::shared_ptr<engine::StartupStep>>& steps);

    void pushRenderStep(const std::shared_ptr<engine::RenderStep>& step);

    void extendRenderSteps(const std::vector<std::shared_ptr<engine::RenderStep>>& steps);

    void pushShutdownStep(const std::shared_ptr<engine::ShutdownStep>& step);

    void extendShutdownSteps(const std::vector<std::shared_ptr<engine::ShutdownStep>>& steps);

    void sendStopSignal();

    void sendRefreshSignal();

    void waitUntilStopped();

private:
    std::atomic<bool> isRunning_ = false;
    std::mutex runningMutex_;
    std::condition_variable runningCv_;
    std::atomic<bool> stopSignal_ = false;
    std::atomic<bool> refreshSignal_ = false;

    sf::Clock deltaClock_;
    bool triggerTrailingRefresh_ = true;

    std::vector<std::shared_ptr<engine::StartupStep>> startupSteps_;
    std::vector<std::shared_ptr<engine::RenderStep>> renderSteps_;
    std::vector<std::shared_ptr<engine::ShutdownStep>> shutdownSteps_;

    void startup();

    void renderFramesContinously();

    bool processEvents();

    bool pollEvents(bool hasFocus, bool alreadyRendering);

    void renderFrame();

    void shutdown();

    void stopRunningState();
};

}
