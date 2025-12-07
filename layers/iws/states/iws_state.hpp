#pragma once

#include <filesystem>
#include <memory>
#include <vector>

#include "server_group.hpp"

namespace iws {

struct IwsState {
    bool showCreateServerModal = false;
    std::filesystem::path workspacePath;
    std::vector<std::shared_ptr<iws::ServerGroup>> serverGroups{
        {std::make_shared<iws::ServerGroup>("alpha"), std::make_shared<iws::ServerGroup>("bravo")}};
    bool updateServerGroups = true;
};

inline std::unique_ptr<iws::IwsState> state;

}
