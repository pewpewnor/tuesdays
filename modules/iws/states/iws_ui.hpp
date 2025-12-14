#pragma once

#include <memory>
#include <vector>

#include "iws/sidebar/iws_server_child_window.hpp"

namespace iws {

struct IwsUi {
    std::vector<IwsServerChildWindow> serverChildWindows;
};

inline std::unique_ptr<iws::IwsUi> ui;

}
