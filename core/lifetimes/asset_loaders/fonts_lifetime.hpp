#pragma once

#include <imgui.h>

#include <memory>
#include <optional>
#include <string_view>

#include "engine/steps/shutdown_step.hpp"
#include "engine/steps/startup_step.hpp"

class FontsLifetime : public engine::StartupStep, public engine::ShutdownStep {
public:
    void onStartup() override;
    void onShutdown() override;

private:
    static constexpr float REGULAR_FONT_SIZE = 20.0F;
    static constexpr float MEDIUM_FONT_SIZE = 24.0F;

    static std::shared_ptr<ImFont> getDefaultFont();

    static std::optional<std::shared_ptr<ImFont>> loadFontFromMemory(const void* data,
                                                                     size_t dataSize,
                                                                     float fontSizePixels,
                                                                     std::string_view fontName);

    static void loadSansFonts();

    static void loadMonoFonts();
};
