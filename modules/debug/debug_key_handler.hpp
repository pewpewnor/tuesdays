#ifdef DEBUG
#pragma once

#include <SFML/Window/Keyboard.hpp>

#include "engine/render_step.hpp"
#include "utils/sfml/combined_key_press_detector.hpp"
#include "utils/sfml/key_press_detector.hpp"

class DebugKeyHandler : public engine::RenderStep {
public:
    void onRender() override;

private:
    CombinedKeyPressDetector f1Andf2Key_{KeyPressDetector{sf::Keyboard::Key::F1},
                                         KeyPressDetector{sf::Keyboard::Key::F2}};
    KeyPressDetector f5Key_{sf::Keyboard::Key::F5};
};
#endif
