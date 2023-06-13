#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "Renderer.h"
#include "Snake.h"
#include "Food.h"
#include "Input.h"
#include "HUD.h"
#include "Menu.h"
class Game {
private:

    Menu menu;
    HUD hud;
    Window window;
    Renderer renderer;
    Snake snake;
    Food food;
    Input inputHandler;
    bool running;
    int snakeSpeedMs;
    bool showMenu = true;
    int readHighScore();
    void updateHighScore(int score);
public:
    Game();
    ~Game();
    void loop();
};

#endif
