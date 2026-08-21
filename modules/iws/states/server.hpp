#pragma once

#include <memory>
#include <string>
#include <vector>

#include "endpoint.hpp"

namespace iws {

struct Server {
public:
    std::string name;
    std::vector<std::shared_ptr<iws::Endpoint>> endpoints;

    Server(std::string_view name) : name(name) {}
};

}
