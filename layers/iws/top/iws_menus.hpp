#pragma once

#include "components/menu.hpp"

class IwsMenuFile : public components::Menu {
public:
    IwsMenuFile();

private:
    void displayContent() override;
};

class IwsMenuEdit : public components::Menu {
public:
    IwsMenuEdit();

private:
    void displayContent() override;
};

class IwsMenuView : public components::Menu {
public:
    IwsMenuView();

private:
    void displayContent() override;
};
