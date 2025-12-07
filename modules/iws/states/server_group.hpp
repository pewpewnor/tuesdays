#pragma once

#include <string>
#include <vector>

#include "endpoint.hpp"

namespace iws {

class ServerGroup {
public:
    std::string name;
    std::vector<iws::Endpoint> endpoints;

    ServerGroup(std::string_view name);
};

}
