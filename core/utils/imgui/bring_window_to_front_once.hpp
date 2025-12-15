#pragma once

class BringWindowToFrontOnce {
public:
    void bringToFrontIfFirstTime();

private:
    bool firstTime_ = true;
};
