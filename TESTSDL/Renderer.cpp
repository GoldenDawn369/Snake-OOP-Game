#include "Renderer.h"

Renderer::Renderer(const Window& window) {
    renderer = SDL_CreateRenderer(window.getWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        // Handle the error here
    }
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
}

void Renderer::clear() const {
    SDL_RenderClear(renderer);
}

void Renderer::present() const {
    SDL_RenderPresent(renderer);
}

void Renderer::drawRect(int x, int y, int width, int height, int r, int g, int b) const {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
    SDL_SetRenderDrawColor(renderer, r, g, b, 255); // Set color based on parameters
    SDL_RenderFillRect(renderer, &rect);
}

SDL_Renderer* Renderer::getRenderer() const {
    return renderer;
}
