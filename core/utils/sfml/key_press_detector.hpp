#pragma once

#include <SFML/Window/Keyboard.hpp>

/*
 *  do not create multiple instances for the same key
 */
class KeyPressDetector {
public:
    KeyPressDetector(sf::Keyboard::Key key);

    /*
     * a single state should only be related to one key.
     * returns true if the key has been pressed.
     * example:
     * if (keyDetector.isPressed()) { showWindow = !showWindow; }
     */
    bool hasBeenPressed();

    /*
     * a single state should only be related to one key.
     * returns true if the key is currently being held down.
     * example:
     * showWindow = keyDetector.isBeingHeld();
     */
    bool isBeingHeld();

    /*
     * a single state should only be related to one key.
     * returns true if the key has stopped being pressed / held.
     * example:
     * if (keyDetector.hasStoppedBeingHeld()) { showWindow = false; }
     * else if (keyDetector.isBeingHeld()) { showWindow = false; }
     */
    bool hasStoppedBeingPressed();

private:
    enum class KeyPressStatus { PressStart, PressOngoing, NoPress, PressStop };

    sf::Keyboard::Key key_;
    bool beingHeld_ = false;

    KeyPressStatus getStatus();
};
