#include "iws.hpp"

#include <memory>

#include "iws/body/iws_body_window.hpp"
#include "iws/iws_lifetime.hpp"
#include "iws/sidebar/iws_sidebar_window.hpp"
#include "iws/top/iws_menubar_window.hpp"
#include "universal/states/universal_state.hpp"

Iws::Iws(const std::shared_ptr<NavbarWindow>& navbarWindow,
         const std::shared_ptr<TopbarWindow>& topbarWindow)
    : navbarWindow_(navbarWindow), topbarWindow_(topbarWindow) {
    auto iwsLifetime = std::make_shared<IwsLifetime>();
    startupSteps.push_back(iwsLifetime);
    shutdownSteps.push_back(iwsLifetime);
}

bool Iws::shouldRender() {
    bool shouldRender = univ::state->currentApp == univ::CurrentApp::Iws;
    if (shouldRender && renderSteps.empty()) {
        addRenderSteps();
    }
    return shouldRender;
}

void Iws::addRenderSteps() {
    auto iwsMenubarWindow = std::make_shared<IwsMenubarWindow>(topbarWindow_);
    renderSteps.push_back(iwsMenubarWindow);

    auto iwsSidebarWindow = std::make_shared<IwsSidebarWindow>(navbarWindow_, topbarWindow_);
    renderSteps.push_back(iwsSidebarWindow);

    auto iwsBodyWindow = std::make_shared<IwsBodyWindow>(topbarWindow_, iwsSidebarWindow);
    renderSteps.push_back(iwsBodyWindow);
}
