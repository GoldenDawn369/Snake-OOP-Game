#include "HUD.h"

HUD::HUD(int x, int y, const std::string& fontPath, int fontSize)
    : x(x), y(y) {
    TTF_Init();
    font = TTF_OpenFont(fontPath.c_str(), fontSize);
    color = { 255, 255, 255, 255 };  // White color
}

void HUD::draw(const Renderer& renderer, int score, int highScore) {
    // Generate the score and high score text
    std::string scoreText = "Score: " + std::to_string(score - 3);
    std::string highScoreText = "High Score: " + std::to_string(highScore);

    // Render the score text onto a surface and create a texture from it
    SDL_Surface* surfaceScore = TTF_RenderText_Solid(font, scoreText.c_str(), color);
    SDL_Texture* textureScore = SDL_CreateTextureFromSurface(renderer.getRenderer(), surfaceScore);

    // Render the high score text onto a surface and create a texture from it
    SDL_Surface* surfaceHighScore = TTF_RenderText_Solid(font, highScoreText.c_str(), color);
    SDL_Texture* textureHighScore = SDL_CreateTextureFromSurface(renderer.getRenderer(), surfaceHighScore);

    // Calculate the dimensions of the score text
    int textW = 0;
    int textH = 0;
    SDL_QueryTexture(textureScore, NULL, NULL, &textW, &textH);

    // Set the destination rectangle for rendering the score text
    SDL_Rect destRectScore = { x, y, textW, textH };

    // Calculate the dimensions of the high score text
    SDL_QueryTexture(textureHighScore, NULL, NULL, &textW, &textH);

    // Set the destination rectangle for rendering the high score text
    SDL_Rect destRectHighScore = { (x + 582), y, textW, textH }; // Adjust the x coordinate as needed

    // Render the score and high score textures onto the renderer using the destination rectangles
    SDL_RenderCopy(renderer.getRenderer(), textureScore, NULL, &destRectScore);
    SDL_RenderCopy(renderer.getRenderer(), textureHighScore, NULL, &destRectHighScore);

    // Clean up resources by freeing surfaces and textures
    SDL_FreeSurface(surfaceScore);
    SDL_DestroyTexture(textureScore);

    SDL_FreeSurface(surfaceHighScore);
    SDL_DestroyTexture(textureHighScore);
}

HUD::~HUD() {
    TTF_CloseFont(font);
    TTF_Quit();
}
