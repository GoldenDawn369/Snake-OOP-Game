// Render.cpp

#include "Render.h"

Render::Render(const char* title, int windowWidth, int windowHeight) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        // Handle error
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        // Handle error
    }
}

Render::~Render() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Render::Clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Set clear color to black
    SDL_RenderClear(renderer);
}

void Render::Present() {
    SDL_RenderPresent(renderer);
}

void Render::DrawFood(const Food& food) {
    SDL_Rect foodRect = { food.GetX(), food.GetY(), food.GetSize(), food.GetSize() };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Set color to red for the food
    SDL_RenderFillRect(renderer, &foodRect);
}

void Render::DrawSnake(const Snake& snake) {
    for (const auto& part : snake.GetBody()) {
        SDL_Rect snakeRect = { part.x, part.y, snake.GetSize(), snake.GetSize() };
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);  // Set color to green for the snake
        SDL_RenderFillRect(renderer, &snakeRect);
    }
}

SDL_Renderer* Render::GetRenderer() const {
    return renderer;
}
