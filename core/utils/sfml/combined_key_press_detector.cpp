#include "combined_key_press_detector.hpp"

#include "key_press_detector.hpp"

CombinedKeyPressDetector::CombinedKeyPressDetector(const KeyPressDetector& keyDetector1,
                                                   const KeyPressDetector& keyDetector2)
    : keyDetector1_(keyDetector1), keyDetector2_(keyDetector2) {}

bool CombinedKeyPressDetector::combineKeyPresses(bool state) {
    if (keyDetector1_.hasBeenPressed() || keyDetector2_.hasBeenPressed()) {
        return !state;
    }
    return state;
}

bool CombinedKeyPressDetector::combineKeyPressAndKeyHeld(bool state) {
    if (!keyDetector1PreviouslyPressed_ && keyDetector2_.hasStoppedBeingPressed()) {
        return false;
    }
    if (keyDetector2_.isBeingHeld()) {
        return true;
    }
    if (keyDetector1_.hasBeenPressed()) {
        keyDetector1PreviouslyPressed_ = !keyDetector1PreviouslyPressed_;
        return !state;
    }
    return state;
}
