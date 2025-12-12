#pragma once

#include <string>
#include <vector>

#include "endpoint.hpp"

namespace iws {

class Server {
public:
    std::string name;
    std::vector<iws::Endpoint> endpoints;

    Server(std::string_view name);
};

}
