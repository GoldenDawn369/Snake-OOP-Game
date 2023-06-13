#include "Food.h"  // Include the header file for the Food class
#include "Snake.h"  // Include the header file for the Snake class
#include <iostream>  // Include the input/output stream library

Food::Food(int x, int y, int size) : GameObject(x, y), size(size) {
    // Food constructor: Initialize the Food object with given coordinates (x, y) and size
}

Food::~Food() {
    // Food destructor: Clean up any resources associated with the Food object
}

void Food::respawn(int windowWidth, int windowHeight, const Snake& snake) {
    // Respawn the food in a new random position within the game window
    do {
        x = rand() % windowWidth;  // Generate a random x coordinate within the window width
        y = rand() % windowHeight;  // Generate a random y coordinate within the window height
    } while (snake.isInside(x, y) || isNearSnake(x, y, snake));  // Repeat if the food is inside the snake or too close to it
}

bool Food::isNearSnake(int x, int y, const Snake& snake) {
    // Check if the food is near any body part of the snake
    int minDistance = 2 * snake.segmentSize;  // Define the minimum distance threshold as twice the snake's segment size

    for (const auto& bodyPart : snake.body) {
        // Calculate the distance between the food and each body part of the snake
        int distance = abs(x - bodyPart.first) + abs(y - bodyPart.second);

        if (distance <= minDistance) {
            return true;  // Return true if the distance is within the minimum threshold
        }
    }

    return false;  // Return false if the food is not near any body part of the snake
}

bool Food::isEaten(const Snake& snake) const {
    // Check if the food has been eaten by the snake
    int snakeX = snake.getX();  // Get the x coordinate of the snake's head
    int snakeY = snake.getY();  // Get the y coordinate of the snake's head
    int snakeSize = snake.getSegmentSize();  // Get the size of the snake's segments

    // Check if the food's coordinates overlap with the snake's head
    bool isEaten = (x < snakeX + snakeSize && x + size > snakeX) &&
        (y < snakeY + snakeSize && y + size > snakeY);

    return isEaten;  // Return true if the food has been eaten, false otherwise
}

void Food::draw(const Renderer& renderer, int r, int g, int b) const {
    // Draw the food on the game renderer with the specified color
    renderer.drawRect(x, y, size, size, r, g, b);
}

void Food::update() {
    // Empty function: Food doesn't require any update logic
}
