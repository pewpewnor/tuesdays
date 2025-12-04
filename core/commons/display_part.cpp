#include "display_part.hpp"

void commons::DisplayPart::display() {
    if (begin()) {
        displayContent();
        endOfDisplay();
    }
}
