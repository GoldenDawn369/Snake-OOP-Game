#ifndef FOOD_H
#define FOOD_H

#include "GameObject.h"
class Snake;
class Food : public GameObject {
private:
    int size;
public:
    Food(int x, int y, int size);
    ~Food();
    bool isNearSnake(int x, int y, const Snake& snake);
    void update() override;
    void draw(const Renderer& renderer, int r, int g, int b) const override;
    bool isEaten(const Snake& snake) const;
    void respawn(int windowWidth, int windowHeight, const Snake& snake);
};

#endif
