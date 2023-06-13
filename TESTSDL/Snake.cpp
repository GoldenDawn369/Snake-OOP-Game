#include "Snake.h"
Snake::Snake(int x, int y, int length, int segmentSize)
    : GameObject(x, y), length(length), segmentSize(segmentSize), speed(5), growthAmount(0) {
    for (int i = 0; i < length; ++i) {
        body.push_back({ x - i, y });
    }
}


Snake::~Snake() {
}

void Snake::changeDirection(Direction newDirection) {
    if (newDirection == UP && direction != DOWN ||
        newDirection == DOWN && direction != UP ||
        newDirection == LEFT && direction != RIGHT ||
        newDirection == RIGHT && direction != LEFT) {
        direction = newDirection;
    }
}
bool Snake::selfHit() const {
    for (auto it = body.begin() + 1; it != body.end(); ++it) {
        if (body.front() == *it) return true;
    }
    return false;
}

bool Snake::hitWall(int windowWidth, int windowHeight) const {
    int headX = body.front().first, headY = body.front().second;
    return headX < 0 || headY < 0 || headX >= windowWidth || headY >= windowHeight;
}
void Snake::update() {
    // Store the old tail position
    int oldTailX = body.back().first;
    int oldTailY = body.back().second;

    // Shift each part of the body to the part in front of it
    for (size_t i = body.size() - 1; i > 0; --i) {
        body[i] = body[i - 1];
    }

    // Update the head based on the direction
    switch (direction) {
    case UP:
        body.front().second -= segmentSize;
        break;
    case DOWN:
        body.front().second += segmentSize;
        break;
    case LEFT:
        body.front().first -= segmentSize;
        break;
    case RIGHT:
        body.front().first += segmentSize;
        break;
    }



    // If the snake should grow, add new tail segments while growthAmount is greater than 0
    while (growthAmount > 0) {
        switch (growDirection) {
        case UP:
            body.push_back({ oldTailX, oldTailY + segmentSize });
            break;
        case DOWN:
            body.push_back({ oldTailX, oldTailY - segmentSize });
            break;
        case LEFT:
            body.push_back({ oldTailX + segmentSize, oldTailY });
            break;
        case RIGHT:
            body.push_back({ oldTailX - segmentSize, oldTailY });
            break;
        }
        --growthAmount;
    }
}

void Snake::grow() {
    growthAmount += 1;
    growDirection = direction;
}



void Snake::draw(const Renderer& renderer, int r, int g, int b) const {
    for (const auto& part : body) {
        renderer.drawRect(part.first, part.second, segmentSize, segmentSize, r, g, b);
    }
}
int Snake::getSegmentSize() const {
    return segmentSize;
}
int Snake::getLength() const {
    return body.size();
}
bool Snake::isInside(int x, int y) const {
    for (const auto& part : body) {
        if (part.first == x && part.second == y) return true;
    }
    return false;
}