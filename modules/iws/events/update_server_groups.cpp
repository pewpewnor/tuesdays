#include "update_server_groups.hpp"

#include "iws/states/iws_state.hpp"
#include "iws/states/iws_ui.hpp"

void iws::events::updateServerGroups() {
    size_t newSize = iws::state->serverGroups.size();
    iws::ui->serverGroupChildWindows.resize(newSize);
    iws::ui->serverGroupChildWindows.shrink_to_fit();
    for (size_t i = 0; i < newSize; i++) {
        std::shared_ptr<iws::ServerGroup> serverGroup = iws::state->serverGroups[i];
        if (iws::ui->serverGroupChildWindows[i]) {
            iws::ui->serverGroupChildWindows[i]->serverGroup = serverGroup;
        } else {
            iws::ui->serverGroupChildWindows[i] = std::make_unique<IwsServerGroup>(serverGroup);
        }
    }
}
