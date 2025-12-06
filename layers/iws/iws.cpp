#include "iws.hpp"

#include <memory>

#include "iws/body/iws_body.hpp"
#include "iws/sidebar/iws_server_groups.hpp"
#include "iws/sidebar/iws_sidebar.hpp"
#include "iws/top/iws_menubar.hpp"
#include "sidebar/iws_server_groups_filter.hpp"
#include "universal/states/universal_state.hpp"

Iws::Iws(const std::shared_ptr<Navbar>& navbar, const std::shared_ptr<Topbar>& topbar) {
    auto iwsMenubar = std::make_shared<IwsMenubar>(topbar);
    renderSteps.push_back(iwsMenubar);

    auto iwsSidebar = std::make_shared<IwsSidebar>(navbar, topbar);
    renderSteps.push_back(iwsSidebar);
    auto iwsServerGroupsFilter = std::make_shared<IwsServerGroupsFilter>(iwsSidebar);
    renderSteps.push_back(iwsServerGroupsFilter);
    auto iwsServerGroups = std::make_shared<IwsServerGroups>(iwsServerGroupsFilter);
    renderSteps.push_back(iwsServerGroups);

    auto iwsBody = std::make_shared<IwsBody>(topbar, iwsSidebar);
    renderSteps.push_back(iwsBody);
}

bool Iws::shouldRender() { return univ::state->currentApp == univ::CurrentApp::Iws; }
