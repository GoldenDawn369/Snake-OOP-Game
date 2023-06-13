#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include "Window.h"
class Renderer {
private:
    SDL_Renderer* renderer;

public:
    Renderer(const Window& window);
    ~Renderer();
    void clear() const;
    void present() const;
    void drawRect(int x, int y, int width, int height, int r, int g, int b) const;
    SDL_Renderer* getRenderer() const;
};

#endif