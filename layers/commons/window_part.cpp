#include "window_part.hpp"

void WindowPart::render() {
    if (shouldDisplay() && begin()) {
        displayContent();
        end();
    }
}
