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
    std::unique_ptr<sf::RenderWindow> window;

    void runContinously();

    void pushStartupStep(const std::shared_ptr<engine::StartupStep>& startupStep);

    void pushRenderStep(const std::shared_ptr<engine::RenderStep>& renderStep);

    void pushShutdownStep(const std::shared_ptr<engine::ShutdownStep>& shutdownStep);

    void pushGroupStep(const std::shared_ptr<engine::GroupStep>& groupStep);

    void sendRefreshSignal(int n = 1);

    void sendStopSignal();

    void sendRestartSignal();

    void waitUntilStopped();

private:
    struct EngineRunningState {
        bool isRunning = false;
        std::mutex mutex;
        std::condition_variable cv;
    };

    EngineRunningState runningState_;
    bool stopSignal_ = false;
    std::atomic<unsigned int> refreshSignal_ = 0;
    bool restartAfterShutdown_ = false;
    sf::Clock deltaClock_;
    unsigned int trailingRefresh_ = 0;

    void startup();

    void renderFramesContinously();

    bool processEvents();

    bool pollEvents(bool alreadyRendering);

    void renderFrame();

    void shutdown();

    void stopRunningState();
};

}
