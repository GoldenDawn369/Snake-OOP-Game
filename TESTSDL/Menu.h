// Menu.h
#ifndef MENU_H
#define MENU_H

#include "Renderer.h"
#include <string>

class Menu {
public:
    Menu(const std::string& title, const Renderer& renderer);

    void draw(const Renderer& renderer);

private:
    std::string title;
    // Add variables for position and color if necessary
};

#endif // MENU_H
