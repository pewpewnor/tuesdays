#pragma once

#include <filesystem>
#include <memory>
#include <vector>

#include "server_group.hpp"

namespace iws {

struct IwsState {
    std::filesystem::path workspacePath;
    std::vector<iws::ServerGroup> serverGroups;
};

inline std::unique_ptr<iws::IwsState> state;

}
