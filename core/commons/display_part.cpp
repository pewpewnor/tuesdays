#include "display_part.hpp"

void commons::DisplayPart::display() {
    if (shouldDisplay() && begin()) {
        displayContent();
        endOfDisplay();
    }
}
