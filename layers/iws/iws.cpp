#include "iws.hpp"

#include <memory>

#include "iws/body/iws_body.hpp"
#include "iws/sidebar/iws_servers_filter.hpp"
#include "iws/sidebar/iws_sidebar.hpp"
#include "iws/top/iws_menubar.hpp"
#include "universal/states/current_app.hpp"

Iws::Iws(const std::shared_ptr<Navbar>& navbar, const std::shared_ptr<Topbar>& topbar) {
    auto iwsMenubar = std::make_shared<IwsMenubar>(topbar);
    renderSteps.push_back(iwsMenubar);

    auto iwsSidebar = std::make_shared<IwsSidebar>(navbar, topbar);
    renderSteps.push_back(iwsSidebar);
    auto iwsServersFilter = std::make_shared<IwsServersFilter>(iwsSidebar);
    renderSteps.push_back(iwsServersFilter);

    auto iwsBody = std::make_shared<IwsBody>(topbar, iwsSidebar);
    renderSteps.push_back(iwsBody);
}

bool Iws::shouldRender() { return univ::currentAppIsIws(); }
