#include "iws_collections_manager.hpp"

#include <algorithm>
#include <optional>

void IwsCollectionsManager::addServer(const std::shared_ptr<iws::Server>& server) {
    servers_.push_back(server);
    serverChildWindows.emplace_back(server);
}

std::optional<std::shared_ptr<iws::Server>> IwsCollectionsManager::findServer(
    std::string_view serverName) {
    auto serverIterator =
        std::ranges::find_if(servers_, [serverName](const std::shared_ptr<iws::Server>& server) {
            return server->name == serverName;
        });

    if (serverIterator == servers_.end()) {
        return {};
    }
    return *serverIterator;
}
