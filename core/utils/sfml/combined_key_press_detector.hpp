#pragma once

#include <SFML/Window/Keyboard.hpp>

#include "key_press_detector.hpp"

// Use this for a single state to be related to multiple keys
class CombinedKeyPressDetector {
public:
    CombinedKeyPressDetector(const KeyPressDetector& keyDetector1,
                             const KeyPressDetector& keyDetector2);

    bool combineKeyPresses(bool state);

    bool combineKeyPressAndKeyHeld(bool state);

    bool combineKeyHelds();

private:
    KeyPressDetector keyDetector1_;
    KeyPressDetector keyDetector2_;
    bool keyDetector1PreviouslyPressed_ = false;
};
