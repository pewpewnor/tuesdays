#pragma once

#include <SFML/Window/Keyboard.hpp>

/**
 *  @brief do not create multiple instances for the same key
 */
class KeyPressDetector {
public:
    KeyPressDetector(sf::Keyboard::Key key);

    /**
     * A single state should only be related to one key.
     * Returns true if the key has been pressed.
     * Example:
     * if (keyDetector.isPressed()) { showWindow = !showWindow; }
     */
    bool hasBeenPressed();

    /**
     * A single state should only be related to one key.
     * Returns true if the key is currently being held down.
     * Example:
     * showWindow = keyDetector.isBeingHeld();
     */
    bool isBeingHeld();

    /*
     * A single state should only be related to one key.
     * Returns true if the key has stopped being pressed / held.
     * Example:
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
