#pragma once

#include <memory>

#include "current_app.hpp"

namespace univ {

struct UniversalState {
    univ::CurrentApp currentApp = univ::CurrentApp::Acm;
};

inline std::unique_ptr<univ::UniversalState> state;

}
