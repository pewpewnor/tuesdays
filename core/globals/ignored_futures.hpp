#pragma once

#include <future>
#include <memory>
#include <mutex>
#include <vector>

namespace g {

class IgnoredFutures {
public:
    std::vector<std::shared_future<void>> futures;
    std::mutex mutex;
};

inline std::unique_ptr<g::IgnoredFutures> ignoredFutures;

}
