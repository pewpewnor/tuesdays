#include "update_server_groups.hpp"

#include "iws/states/iws_state.hpp"
#include "iws/states/iws_ui.hpp"

void iws::events::updateServerGroups() {
    size_t newSize = iws::state->servers.size();
    iws::ui->serverChildWindows.resize(newSize);
    iws::ui->serverChildWindows.shrink_to_fit();
    for (size_t i = 0; i < newSize; i++) {
        std::shared_ptr<iws::Server> server = iws::state->servers[i];
        if (iws::ui->serverChildWindows[i]) {
            iws::ui->serverChildWindows[i]->server = server;
        } else {
            iws::ui->serverChildWindows[i] = std::make_unique<IwsServerChildWindow>(server);
        }
    }
}
