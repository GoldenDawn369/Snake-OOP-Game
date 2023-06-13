#include "Game.h"  // Include the header file for the Game class
#include "HUD.h"  // Include the header file for the HUD class
#include <iostream>  // Include the input/output stream library
#include <chrono>  // Include the chrono library for time-related operations
#include <thread>  // Include the thread library for sleep operations
#include <fstream>  // Include the fstream library for file I/O
using std::cout;
using std::endl;

Game::Game()
    : window("Snake Game", 800, 600),  // Create a window with the specified title and dimensions
    renderer(window),  // Create a renderer associated with the window
    snake(400, 300, 3, 20),  // Create a snake object with the specified initial position, length, and segment size
    food(200, 200, 20),  // Create a food object with the specified position and size
    running(true),  // Set the running flag to true
    snakeSpeedMs(42),  // Set the snake's speed in milliseconds
    hud(10, 10, "Raleway-Bold.ttf", 24),  // Create an HUD object with the specified position, font file, and font size
    menu("Press Enter to Start", renderer),  // Create a menu object with the specified text and renderer
    showMenu(true) {}  // Set the showMenu flag to true to display the menu initially

Game::~Game() {
    Window::cleanSDL();  // Clean up SDL resources when the game is destroyed
}

int Game::readHighScore() {
    std::ifstream file("highscore.txt");  // Open the high score file for reading
    if (!file) {
        return 0;  // If the file does not exist, return 0 as the high score
    }
    int highScore;
    file >> highScore;  // Read the high score from the file
    file.close();  // Close the file
    return highScore;  // Return the high score
}

void Game::updateHighScore(int score) {
    int highScore = readHighScore();  // Read the current high score
    if (score > highScore) {
        highScore = score;  // Update the high score if the current score is higher
        std::ofstream file("highscore.txt");  // Open the high score file for writing
        file << highScore;  // Write the updated high score to the file
        file.close();  // Close the file
    }
}

void Game::loop() {
    while (running) {
        auto start = std::chrono::high_resolution_clock::now();  // Record the start time of the loop

        inputHandler.processInput(snake);  // Handle input events

        if (showMenu) {
            // Check if enter is pressed to start the game
            if (inputHandler.isEnterPressed()) {
                showMenu = false;  // Hide the menu and start the game
            }

            SDL_SetRenderDrawColor(renderer.getRenderer(), 0, 0, 0, 255);  // Set the renderer's draw color to black
            renderer.clear();  // Clear the renderer's buffer
            menu.draw(renderer);  // Draw the menu on the renderer
            renderer.present();  // Update the screen with the rendered content
        }
        else {
            snake.update();  // Update the snake's position and state

            // Check if the snake hits itself or the wall
            if (snake.selfHit() || snake.hitWall(window.getWidth(), window.getHeight())) {
                updateHighScore(snake.getLength() - 3);  // Update the high score
                running = false;  // Stop the game loop
            }

            // Check if the food is eaten
            if (food.isEaten(snake)) {
                snake.grow();  // Make the snake grow
                food.respawn(window.getWidth(), window.getHeight(), snake);  // Respawn the food
            }

            SDL_SetRenderDrawColor(renderer.getRenderer(), 0, 0, 0, 255);  // Set the renderer's draw color to black
            renderer.clear();  // Clear the renderer's buffer

            snake.draw(renderer, 0, 255, 0);  // Draw the snake on the renderer with green color
            food.draw(renderer, 255, 0, 0);  // Draw the food on the renderer with red color
            hud.draw(renderer, snake.getLength(), readHighScore());  // Draw the HUD on the renderer
            renderer.present();  // Update the screen with the rendered content
        }

        auto end = std::chrono::high_resolution_clock::now();  // Record the end time of the loop
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();  // Calculate the loop duration

        if (duration < snakeSpeedMs) {
            std::this_thread::sleep_for(std::chrono::milliseconds(snakeSpeedMs - duration));  // Sleep to control the game speed
        }
    }
}
