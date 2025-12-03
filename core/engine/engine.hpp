#pragma once

#include <imgui.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <atomic>
#include <condition_variable>
#include <mutex>

#include "engine/steps/group_step.hpp"

namespace engine {

class Engine : private GroupStep {
public:
    std::shared_ptr<sf::RenderWindow> window;
    std::atomic<bool> renderOnIdle = false;

    void runContinously();

    void pushStartupStep(const std::shared_ptr<engine::StartupStep>& startupStep);

    void pushRenderStep(const std::shared_ptr<engine::RenderStep>& renderStep);

    void pushShutdownStep(const std::shared_ptr<engine::ShutdownStep>& shutdownStep);

    void pushGroupStep(const std::shared_ptr<engine::GroupStep>& groupStep);

    void sendStopSignal();

    void sendRefreshSignal(int n = 1);

    void sendRestartSignal();

    void waitUntilStopped();

private:
    std::atomic<bool> isRunning_ = false;
    std::mutex runningMutex_;
    std::condition_variable runningCv_;
    std::atomic<bool> stopSignal_ = false;
    std::atomic<unsigned int> refreshSignal_ = 0;
    std::atomic<bool> restartAfterShutdown_ = false;
    sf::Clock deltaClock_;
    bool triggerTrailingRefresh_ = true;

    void startup();

    void renderFramesContinously();

    bool processEvents();

    bool pollEvents(bool alreadyRendering);

    void renderFrame();

    void shutdown();

    void stopRunningState();
};

}
