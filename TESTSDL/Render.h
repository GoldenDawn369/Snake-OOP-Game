// Render.h

#pragma once
#include <SDL.h>
#include "Game.h"
#include "Snake.h"
#include "Food.h"

class Render {
public:
    Render(const char* title, int windowWidth, int windowHeight);
    ~Render();

    void Clear();
    void Present();
    void DrawFood(const Food& food);
    void DrawSnake(const Snake& snake);
    SDL_Renderer* GetRenderer() const;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
