#pragma once

namespace commons {

class ChildWindowPart {
public:
    ChildWindowPart() = default;
    ChildWindowPart(const ChildWindowPart&) = default;
    ChildWindowPart(ChildWindowPart&&) = delete;
    ChildWindowPart& operator=(const ChildWindowPart&) = default;
    ChildWindowPart& operator=(ChildWindowPart&&) = delete;
    virtual ~ChildWindowPart() = default;

    void display();

private:
    virtual bool beginChildWindow() = 0;

    virtual void displayChildWindowContent() = 0;
};

}
