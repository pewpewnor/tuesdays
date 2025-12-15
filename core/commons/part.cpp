#include "part.hpp"

void commons::Part::display() {
    if (begin()) {
        renderContent();
        endContent();
    }
    end();
}
