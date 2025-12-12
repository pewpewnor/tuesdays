#pragma once

#include <filesystem>
#include <memory>
#include <vector>

#include "server.hpp"

namespace iws {

struct IwsState {
    bool showCreateServerModal = false;
    std::filesystem::path workspacePath;
    std::vector<std::shared_ptr<iws::Server>> servers;
};

inline std::unique_ptr<iws::IwsState> state;

}
