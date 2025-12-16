#pragma once

#include <filesystem>
#include <memory>

#include "iws/states/iws_collections_manager.hpp"

namespace iws {

struct IwsState {
    bool showCreateServerModal = false;
    std::filesystem::path workspacePath;
    IwsCollectionsManager collections;
};

inline std::unique_ptr<iws::IwsState> state;

}
