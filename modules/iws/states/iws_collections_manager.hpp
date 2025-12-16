#pragma once

#include <optional>
#include <vector>

#include "iws/sidebar/iws_server_child_window.hpp"
#include "iws/states/server.hpp"

class IwsCollectionsManager {
public:
    std::vector<IwsServerChildWindow> serverChildWindows;

    void addServer(const std::shared_ptr<iws::Server>& server);

    std::optional<std::shared_ptr<iws::Server>> findServer(std::string_view serverName);

private:
    std::vector<std::shared_ptr<iws::Server>> servers_;
};
