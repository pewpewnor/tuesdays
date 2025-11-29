#pragma once

#include <filesystem>
#include <memory>

namespace iws {

struct IwsState {
    std::filesystem::path workspacePath;
};

inline std::unique_ptr<iws::IwsState> state;

}
