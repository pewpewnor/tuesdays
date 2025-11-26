#pragma once

#include <imgui.h>

#include <filesystem>

#include "engine/shutdown_step.hpp"
#include "engine/startup_step.hpp"
#include "utils/results.hpp"

class FontsLifetime : public engine::StartupStep, public engine::ShutdownStep {
public:
    void onStartup() override;

    void onShutdown() override;

private:
    static void loadSansFonts(const std::filesystem::path& fontsPath);

    static void loadMonoFonts(const std::filesystem::path& fontsPath);

    static Result<ImFont*> loadFont(const std::filesystem::path& fontFilePath, float fontSize);
};
