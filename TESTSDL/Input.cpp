// Input.cpp
#include "Input.h"

void Input::processInput(Snake& snake) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            exit(0);  // If the user closes the window, exit the program
        }
        else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
            case SDLK_RETURN:
                enterPressed = true;  // Set enterPressed flag to true if the Enter key is pressed
                break;
            case SDLK_UP:
                snake.changeDirection(Snake::Direction::UP);  // Change snake direction to UP if Up arrow key is pressed
                break;
            case SDLK_DOWN:
                snake.changeDirection(Snake::Direction::DOWN);  // Change snake direction to DOWN if Down arrow key is pressed
                break;
            case SDLK_LEFT:
                snake.changeDirection(Snake::Direction::LEFT);  // Change snake direction to LEFT if Left arrow key is pressed
                break;
            case SDLK_RIGHT:
                snake.changeDirection(Snake::Direction::RIGHT);  // Change snake direction to RIGHT if Right arrow key is pressed
                break;
            }
        }
    }
}


bool Input::isEnterPressed() {
    bool wasEnterPressed = enterPressed;  // Store the current value of enterPressed
    enterPressed = false;  // Reset the enterPressed flag to false after checking
    return wasEnterPressed;  // Return the stored value
}
