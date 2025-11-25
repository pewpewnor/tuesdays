#include "ignored_futures.hpp"

#include <spdlog/spdlog.h>

namespace g {

std::unique_ptr<g::IgnoredFutures> ignoredFutures;

}

g::IgnoredFutures::~IgnoredFutures() {
    std::lock_guard<std::mutex> lock(mutex);
    spdlog::debug("Waiting for {} ignored futures to finish...", futures.size());
    for (const std::shared_future<void>& future : futures) {
        future.wait_for(std::chrono::seconds(10));
    }
}
