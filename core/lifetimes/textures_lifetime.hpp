#pragma once

#include <imgui-SFML.h>

#include <filesystem>

#include "engine/shutdown_step.hpp"
#include "engine/startup_step.hpp"

class TexturesLifetime : public engine::StartupStep, public engine::ShutdownStep {
public:
    void onStartup() override;

    void onShutdown() override;

private:
    static std::filesystem::path imagesPath;

    static void loadTexture(sf::Texture& texture, std::string_view fileName);

    static void loadTextureFromSvg(sf::Texture& texture, std::string_view fileName);

    static bool smoothenTexture(sf::Texture& texture);
};
