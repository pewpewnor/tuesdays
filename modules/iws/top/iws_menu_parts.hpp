#pragma once

#include "layout/menu_part.hpp"

class IwsMenuPartFile : public components::MenuPart {
public:
    IwsMenuPartFile();

private:
    void displayContent() override;
};

class IwsMenuPartEdit : public components::MenuPart {
public:
    IwsMenuPartEdit();

private:
    void displayContent() override;
};

class IwsMenuPartView : public components::MenuPart {
public:
    IwsMenuPartView();

private:
    void displayContent() override;
};
