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
    static constexpr float MEDIUM_FONT_SIZE = 20;
    static constexpr float LARGE_FONT_SIZE = 32;
    static std::filesystem::path fontsPath;

    static std::shared_ptr<ImFont> getDefaultFont();

    static Result<std::shared_ptr<ImFont>> loadFont(const std::filesystem::path& fontFilePath,
                                                    float fontSize);

    void loadSansFonts();

    void loadMonoFonts();
};
