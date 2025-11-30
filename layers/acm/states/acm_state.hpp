#pragma once

#include <filesystem>
#include <memory>

namespace acm {

struct AcmState {
    std::filesystem::path workspacePath;
};

inline std::unique_ptr<acm::AcmState> state;

}
