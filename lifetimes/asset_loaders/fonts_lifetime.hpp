#pragma once

#include <imgui.h>

#include <memory>
#include <string_view>

#include "engine/steps/shutdown_step.hpp"
#include "engine/steps/startup_step.hpp"
#include "utils/results.hpp"

class FontsLifetime : public engine::StartupStep, public engine::ShutdownStep {
public:
    void onStartup() override;
    void onShutdown() override;

private:
    static constexpr float REGULAR_FONT_SIZE = 20.0F;
    static constexpr float MEDIUM_FONT_SIZE = 24.0F;

    static std::shared_ptr<ImFont> getDefaultFont();

    static Result<std::shared_ptr<ImFont>> loadFontFromMemory(const void* data, int dataSize,
                                                              float fontSizePixels);

    static void logFontLoadError(std::string_view fontName, const std::string& errorMsg);

    static void loadSansFonts();

    static void loadMonoFonts();
};
