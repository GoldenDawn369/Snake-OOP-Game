#include "Window.h"

Window::Window(const char* title, int width, int height) : width(width), height(height) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        // Handle the error here
    }
}

Window::~Window() {
    SDL_DestroyWindow(window);
}

int Window::getWidth() const {
    return width;
}

int Window::getHeight() const {
    return height;
}

SDL_Window* Window::getWindow() const {
    return window;
}

void Window::initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    }
}

void Window::cleanSDL() {
    SDL_Quit();
}