#pragma once

#include <string>
#include <vector>

#include "endpoint.hpp"

namespace iws {

struct ServerGroup {
    std::string name;
    std::vector<iws::Endpoint> endpoints;
};

}
