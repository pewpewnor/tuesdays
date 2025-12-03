#pragma once

#include <imgui-SFML.h>
#include <imgui.h>

#include "engine/steps/shutdown_step.hpp"
#include "engine/steps/startup_step.hpp"

class TexturesLifetime : public engine::StartupStep, public engine::ShutdownStep {
public:
    void onStartup() override;

    void onShutdown() override;

private:
    static void loadTextureFromMemory(sf::Texture& texture, const void* data, size_t size,
                                      std::string_view debugName);

    static bool smoothenTexture(sf::Texture& texture);
};
