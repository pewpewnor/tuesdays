#pragma once

namespace commons {

class DisplayPart {
public:
    DisplayPart() = default;
    DisplayPart(const DisplayPart&) = default;
    DisplayPart(DisplayPart&&) = delete;
    DisplayPart& operator=(const DisplayPart&) = default;
    DisplayPart& operator=(DisplayPart&&) = delete;
    virtual ~DisplayPart() = default;

    void display();

private:
    virtual bool shouldDisplay() { return true; };

    virtual bool begin() = 0;

    virtual void displayContent() = 0;

    virtual void endOfDisplay() = 0;
};

}
