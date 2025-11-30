#include "window_part.hpp"

void WindowPart::render() {
    if (begin()) {
        renderContent();
        end();
    }
}
