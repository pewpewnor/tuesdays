#pragma once

#include <memory>

#include "commons/child_window_part.hpp"
#include "iws/sidebar/iws_server_group_dropdown.hpp"
#include "iws/states/server_group.hpp"

class IwsServerGroup : public commons::ChildWindowPart {
public:
    std::shared_ptr<iws::ServerGroup> serverGroup;

    IwsServerGroup(const std::shared_ptr<iws::ServerGroup>& serverGroup);

private:
    IwsServerGroupDropdown serverGroupDropdown_;

    bool beginChildWindow() override;

    void displayChildWindowContent() override;
};
