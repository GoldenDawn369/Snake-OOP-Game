#include "Game.h"
int main(int argc, char* argv[]) {
    Window::initSDL();

    Game game;
    game.loop();

    return 0;
}