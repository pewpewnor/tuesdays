#pragma once

#include <imgui.h>

#include <filesystem>

#include "engine/shutdown_step.hpp"
#include "engine/startup_step.hpp"
#include "utils/results.hpp"

class FontsLifetime : public engine::StartupStep, public engine::ShutdownStep {
public:
    std::string sansRegularFileName = "Geist-Regular.ttf";
    std::string sansBoldFileName = "Geist-Bold.ttf";
    std::string monoRegularFileName = "GeistMono-Regular.ttf";
    std::string monoBoldFileName = "GeistMono-Bold.ttf";

    void onStartup() override;

    void onShutdown() override;

private:
    static std::filesystem::path fontsPath;

    static Result<ImFont*> loadFont(const std::filesystem::path& fontFilePath, float fontSize);

    void loadSansFonts();

    void loadMonoFonts();
};
