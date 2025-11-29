#include "tasks_lifetime.hpp"

#include "globals/ignored_futures.hpp"
#include "spdlog/spdlog.h"

void TasksLifetime::onStartup() { g::ignoredFutures = std::make_unique<g::IgnoredFutures>(); }

void TasksLifetime::onShutdown() {
    std::lock_guard<std::mutex> lock(g::ignoredFutures->mutex);
    spdlog::debug("Waiting for {} ignored futures to finish...", g::ignoredFutures->futures.size());
    for (const std::shared_future<void>& future : g::ignoredFutures->futures) {
        future.wait_for(std::chrono::minutes(1));
    }
    g::ignoredFutures.reset();
    spdlog::debug("Ignored futures has finished");
}
