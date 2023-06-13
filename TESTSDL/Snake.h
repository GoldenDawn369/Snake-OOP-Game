#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "GameObject.h"
#include <deque> 
class Snake : public GameObject {
public:
    enum Direction { UP, DOWN, LEFT, RIGHT };
private:
    int growthAmount;
    int length;  // Length of the snake
    int speed;
    std::pair<int, int> lastTailPosition;
    Direction growDirection = RIGHT;  // Initialize it to any value
    bool shouldGrow = false;  // Indicates whether the snake should grow in the next update
    Direction direction;

public:
    Snake(int x, int y, int length, int segmentSize);
    ~Snake();
    int segmentSize;
    std::deque<std::pair<int, int>> body; // Each pair represents x, y coordinate
    int getLength() const;
    void update() override;
    void draw(const Renderer& renderer, int r, int g, int b) const override;
    void changeDirection(Direction newDirection);
    bool selfHit() const;
    bool hitWall(int windowWidth, int windowHeight) const;
    void grow();
    int getX() const override { return body.front().first; }
    int getY() const override { return body.front().second; }
    // New function to get the size of the snake
    int getSegmentSize() const;
    bool isInside(int x, int y) const;
};

#endif
