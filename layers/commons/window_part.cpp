#include "window_part.hpp"

void WindowPart::render() {
    if (shouldRender() && begin()) {
        renderContent();
        end();
    }
}
