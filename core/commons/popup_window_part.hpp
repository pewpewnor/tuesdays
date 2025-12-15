#pragma once

#include "commons/part.hpp"

namespace commons {

class PopupWindowPart : public Part {
public:
    PopupWindowPart() = default;
    PopupWindowPart(const PopupWindowPart&) = default;
    PopupWindowPart(PopupWindowPart&&) = delete;
    PopupWindowPart& operator=(const PopupWindowPart&) = default;
    PopupWindowPart& operator=(PopupWindowPart&&) = delete;
    ~PopupWindowPart() override = default;

private:
    void endContent() override;
};

}
