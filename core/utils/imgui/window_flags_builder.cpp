#include "window_flags_builder.hpp"

WindowFlagsBuilder WindowFlagsBuilder::add(ImGuiWindowFlags_ flag) {
    flags_ = static_cast<ImGuiWindowFlags>(static_cast<unsigned int>(flags_) |
                                           static_cast<unsigned int>(flag));
    return *this;
}

ImGuiWindowFlags WindowFlagsBuilder::build() { return flags_; }
