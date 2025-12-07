#pragma once

#include <memory>

#include "current_app.hpp"

namespace univ {

struct UniversalState {
    univ::CurrentApp currentApp = univ::CurrentApp::Iws;
};

inline std::unique_ptr<univ::UniversalState> state;

}
