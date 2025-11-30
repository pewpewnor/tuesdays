#pragma once

#include <string>
#include <unordered_map>

namespace iws {

struct Endpoint {
    std::string name;
    std::string apiPath;
    std::string httpMethod;
    int statusCode;
    std::unordered_map<std::string, std::string> headers;
    std::string body;
};

}
