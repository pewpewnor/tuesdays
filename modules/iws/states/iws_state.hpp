#pragma once

#include <filesystem>
#include <memory>
#include <vector>

#include "iws/sidebar/iws_server_child_window.hpp"

namespace iws {

struct IwsState {
    bool showCreateServerModal = false;
    std::filesystem::path workspacePath;
    std::vector<IwsServerChildWindow> serverChildWindows;
};

inline std::unique_ptr<iws::IwsState> state;

}
