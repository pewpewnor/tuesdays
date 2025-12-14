#pragma once

#include <filesystem>
#include <memory>

namespace iws {

struct IwsState {
    bool showCreateServerModal = false;
    std::filesystem::path workspacePath;
};

inline std::unique_ptr<iws::IwsState> state;

}
