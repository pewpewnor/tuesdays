#pragma once

#include "commons/part.hpp"

namespace commons {

class ChildWindowPart : public Part {
public:
    ChildWindowPart() = default;
    ChildWindowPart(const ChildWindowPart&) = default;
    ChildWindowPart(ChildWindowPart&&) = delete;
    ChildWindowPart& operator=(const ChildWindowPart&) = default;
    ChildWindowPart& operator=(ChildWindowPart&&) = delete;
    ~ChildWindowPart() override = default;

private:
    void endContent() override;
};

}
