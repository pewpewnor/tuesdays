#include "iws.hpp"

#include <memory>

#include "iws/body/iws_body_window.hpp"
#include "iws/iws_lifetime.hpp"
#include "iws/sidebar/iws_sidebar_window.hpp"
#include "iws/top/iws_menubar_window.hpp"
#include "universal/states/universal_state.hpp"

Iws::Iws(const std::shared_ptr<NavbarWindow>& navbar, const std::shared_ptr<TopbarWindow>& topbar) {
    auto iwsLifetime = std::make_shared<IwsLifetime>();
    startupSteps.push_back(iwsLifetime);
    shutdownSteps.push_back(iwsLifetime);

    auto iwsMenubar = std::make_shared<IwsMenubarWindow>(topbar);
    renderSteps.push_back(iwsMenubar);

    auto iwsSidebar = std::make_shared<IwsSidebarWindow>(navbar, topbar);
    renderSteps.push_back(iwsSidebar);

    auto iwsBody = std::make_shared<IwsBodyWindow>(topbar, iwsSidebar);
    renderSteps.push_back(iwsBody);
}

bool Iws::shouldRender() { return univ::state->currentApp == univ::CurrentApp::Iws; }
