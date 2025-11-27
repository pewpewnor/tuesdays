#pragma once

#include <memory>

namespace univ {

enum class CurrentApp { Acm, Is, Dbm };

struct UniversalState {
    CurrentApp currentApp = CurrentApp::Acm;
};

inline std::unique_ptr<univ::UniversalState> state;

}
