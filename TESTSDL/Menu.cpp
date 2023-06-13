// Menu.cpp
#include "Menu.h"
#include <SDL_ttf.h>

Menu::Menu(const std::string& title, const Renderer& renderer)
    : title(title) {

}

void Menu::draw(const Renderer& renderer) {

    TTF_Font* font = TTF_OpenFont("Raleway-Bold.ttf", 42);
    SDL_Color color = { 255, 255, 255 };  // white color

    SDL_Surface* surface = TTF_RenderText_Solid(font, title.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), surface);

    int textW = 0;
    int textH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &textW, &textH);
    SDL_Rect destRect = { 220, 270, textW, textH };  // Change the position as necessary

    SDL_RenderCopy(renderer.getRenderer(), texture, NULL, &destRect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}
