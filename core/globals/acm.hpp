#pragma once

#include <memory>

namespace acm {

struct AcmState {};

inline std::unique_ptr<acm::AcmState> state;

}
