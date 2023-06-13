#ifndef HUD_H
#define HUD_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "Renderer.h"
#include <string>

class HUD {
public:
    HUD(int x, int y, const std::string& fontPath, int fontSize);
    ~HUD();
    void draw(const Renderer& renderer, int score,int highScore);

private:
    int x, y;
    TTF_Font* font;
    SDL_Color color;
};

#endif //HUD_H
