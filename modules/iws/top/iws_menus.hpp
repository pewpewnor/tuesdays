#pragma once

#include "commons/components.hpp"

class IwsMenuFile : public components::Menu {
public:
    IwsMenuFile();

private:
    void renderContent() override;
};

class IwsMenuEdit : public components::Menu {
public:
    IwsMenuEdit();

private:
    void renderContent() override;
};

class IwsMenuView : public components::Menu {
public:
    IwsMenuView();

private:
    void renderContent() override;
};
