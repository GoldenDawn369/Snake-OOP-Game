// Input.h
#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>
#include "Snake.h"

class Input {
public:
    void processInput(Snake& snake);
    bool isEnterPressed();  

private:
    SDL_Event event;
    bool enterPressed;  
};

#endif