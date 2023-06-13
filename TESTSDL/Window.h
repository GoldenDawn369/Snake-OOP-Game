#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>

class Window {
private:
    SDL_Window* window;
    int width, height;

public:
    Window(const char* title, int width, int height);
    ~Window();
    int getWidth() const;
    int getHeight() const;
    SDL_Window* getWindow() const;

    static void initSDL();
    static void cleanSDL();
};

#endif