#pragma once

class WindowPart {
public:
    WindowPart() = default;
    WindowPart(const WindowPart&) = default;
    WindowPart(WindowPart&&) = delete;
    WindowPart& operator=(const WindowPart&) = default;
    WindowPart& operator=(WindowPart&&) = delete;
    virtual ~WindowPart() = default;

    void render();

protected:
    virtual bool begin() = 0;

    virtual void renderContent() = 0;

    virtual void end() = 0;
};
