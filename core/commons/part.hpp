#pragma once

namespace commons {

class Part {
public:
    Part() = default;
    Part(const Part&) = default;
    Part(Part&&) = delete;
    Part& operator=(const Part&) = default;
    Part& operator=(Part&&) = delete;
    virtual ~Part() = default;

    void display();

private:
    virtual bool begin() = 0;

    virtual void renderContent() = 0;

    virtual void endContent() {}

    virtual void end() {}
};

}
