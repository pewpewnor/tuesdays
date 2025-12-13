#include "engine.hpp"

#include <imgui-SFML.h>
#include <spdlog/spdlog.h>

#include <SFML/System/Sleep.hpp>
#include <mutex>
#include <optional>
#include <stdexcept>

#include "SFML/Window/Event.hpp"
#include "engine/steps/group_step.hpp"
#include "utils/assertions.hpp"
#include "utils/scopes/scope_exit.hpp"

namespace {

constexpr sf::Time fpsToTimePerFrame(int fps) { return sf::milliseconds(1000 / fps); }

}

void engine::Engine::runContinously() {
    if (std::lock_guard<std::mutex> lock(runningState_.mutex); runningState_.isRunning) {
        throw std::runtime_error("engine is already running");
    }
    do {
        restartAfterShutdown_ = false;
        ScopeExit scopeExit([this]() { shutdown(); });
        startup();
        renderFramesContinously();
    } while (restartAfterShutdown_);
}

void engine::Engine::pushStartupStep(const std::shared_ptr<engine::StartupStep>& startupStep) {
#ifdef DEBUG
    {
        std::lock_guard<std::mutex> lock(runningState_.mutex);
        ASSERT(!runningState_.isRunning, "only add step while engine is not running");
    }
#endif
    startupSteps.push_back(startupStep);
}

void engine::Engine::pushRenderStep(const std::shared_ptr<engine::RenderStep>& renderStep) {
#ifdef DEBUG
    {
        std::lock_guard<std::mutex> lock(runningState_.mutex);
        ASSERT(!runningState_.isRunning, "only add step while engine is not running");
    }
#endif
    renderSteps.push_back(renderStep);
}

void engine::Engine::pushShutdownStep(const std::shared_ptr<engine::ShutdownStep>& shutdownStep) {
#ifdef DEBUG
    {
        std::lock_guard<std::mutex> lock(runningState_.mutex);
        ASSERT(!runningState_.isRunning, "only add step while engine is not running");
    }
#endif
    shutdownSteps.push_back(shutdownStep);
}

void engine::Engine::pushGroupStep(const std::shared_ptr<engine::GroupStep>& groupStep) {
#ifdef DEBUG
    {
        std::lock_guard<std::mutex> lock(runningState_.mutex);
        ASSERT(!runningState_.isRunning, "only add step while engine is not running");
    }
#endif
    startupSteps.push_back(groupStep);
    renderSteps.push_back(groupStep);
    shutdownSteps.push_back(groupStep);
}

void engine::Engine::sendRefreshSignal(int n) {
    ASSERT(n > 0, "number of refresh signal to be sent must be positive");
    spdlog::debug("Sending {} refresh signal to engine ...", n);
    refreshSignal_ += n;
}

void engine::Engine::sendRestartSignal() {
    spdlog::debug("Sending restart signal to engine ...");
    restartAfterShutdown_ = true;
    stopSignal_ = true;
}

void engine::Engine::sendStopSignal() {
    spdlog::debug("Sending stop signal to engine ...");
    stopSignal_ = true;
}

void engine::Engine::waitUntilStopped() {
    std::unique_lock<std::mutex> lock(runningState_.mutex);
    runningState_.cv.wait(lock, [this] { return !runningState_.isRunning; });
}

void engine::Engine::startup() {
    trailingRefresh_ = 3;
    refreshSignal_ = 0;
    spdlog::debug("Engine executing startup steps ...");
    onStartup();
}

void engine::Engine::renderFramesContinously() {
    sf::Clock clock;
    sf::Time nextFrameTime = clock.getElapsedTime();

    while (!stopSignal_ && window->isOpen()) {
        bool refresh = processEvents();
        if (refresh) {
            renderFrame();
            nextFrameTime += fpsToTimePerFrame(60);
        } else {
            nextFrameTime += fpsToTimePerFrame(20);
        }

        if (sf::Time currentTime = clock.getElapsedTime(); currentTime < nextFrameTime) {
            sf::sleep(nextFrameTime - currentTime);
        } else {
            nextFrameTime = currentTime;
        }
    }
    spdlog::debug("Engine has stopped rendering frames");
}

bool engine::Engine::processEvents() {
    bool hasFocus = window->hasFocus();
    bool refresh = false;
    bool refreshNeedsTrailing = false;

    if (trailingRefresh_ > 0) {
        refresh = true;
        trailingRefresh_--;
    }

    if (pollEvents(refresh)) {
        refresh = true;
        refreshNeedsTrailing = true;
    }
    if (!refresh) {
        if (hasFocus && ImGui::GetIO().WantTextInput) {
            refresh = true;
        } else {
            unsigned int expected = refreshSignal_;
            if (expected > 0 && refreshSignal_.compare_exchange_strong(expected, expected - 1)) {
                refresh = true;
                refreshNeedsTrailing = true;
            }
        }
    }

    if (refreshNeedsTrailing) {
        trailingRefresh_++;
    }
    return refresh;
}

bool engine::Engine::pollEvents(bool alreadyRendering) {
    bool refresh = false;
    while (const std::optional<sf::Event> optionalEvent = window->pollEvent()) {
        if (!optionalEvent.has_value()) {
            spdlog::debug("Dectected an empty event, skipping...");
            continue;
        }
        sf::Event event = optionalEvent.value();

        if (event.is<sf::Event::Closed>()) {
            sendStopSignal();
            break;
        }
        /*
         * do not process FocusLost event so ImGui doesn't know about it, thus we can react to
         * things like hover over items even when focus is lost
         */
        if (event.is<sf::Event::FocusLost>()) {
            refresh = true;
            continue;
        }
        ImGui::SFML::ProcessEvent(*window, event);
        if (!alreadyRendering && !refresh &&
            (event.is<sf::Event::FocusGained>() || event.is<sf::Event::Resized>() ||
             event.is<sf::Event::MouseButtonPressed>() ||
             event.is<sf::Event::MouseButtonReleased>() || event.is<sf::Event::MouseEntered>() ||
             event.is<sf::Event::MouseLeft>() || event.is<sf::Event::MouseMoved>() ||
             event.is<sf::Event::MouseWheelScrolled>() || event.is<sf::Event::KeyPressed>() ||
             event.is<sf::Event::KeyReleased>() || event.is<sf::Event::TextEntered>() ||
             event.is<sf::Event::JoystickButtonPressed>() ||
             event.is<sf::Event::JoystickButtonReleased>() ||
             event.is<sf::Event::JoystickMoved>() || event.is<sf::Event::JoystickConnected>() ||
             event.is<sf::Event::JoystickDisconnected>())) {
            refresh = true;
        }
    }
    return refresh;
}

void engine::Engine::renderFrame() {
    ImGui::SFML::Update(*window, deltaClock_.restart());

    onRender();

    window->clear(sf::Color::Black);
    ImGui::SFML::Render(*window);
    window->display();
}

void engine::Engine::shutdown() {
    ScopeExit scopeExit([this]() { stopRunningState(); });
    spdlog::debug("Engine executing shutdown steps ...");
    onShutdown();
}

void engine::Engine::stopRunningState() {
    stopSignal_ = false;
    std::lock_guard<std::mutex> lock(runningState_.mutex);
    runningState_.isRunning = false;
    runningState_.cv.notify_all();
}
