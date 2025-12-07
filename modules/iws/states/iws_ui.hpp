#pragma once

#include <memory>
#include <vector>

#include "iws/sidebar/iws_server_group.hpp"

namespace iws {

struct IwsUi {
    std::vector<std::unique_ptr<IwsServerGroup>> serverGroupChildWindows;
};

inline std::unique_ptr<iws::IwsUi> ui;

}
