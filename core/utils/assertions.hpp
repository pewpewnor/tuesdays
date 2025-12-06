#pragma once

#include <cassert>

#define ASSERT(condition, message) assert((condition) && (message))

#define ASSERT_UNREACHABLE(message) ASSERT(false, message)
