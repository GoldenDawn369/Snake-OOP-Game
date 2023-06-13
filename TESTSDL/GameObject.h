#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Renderer.h"

class GameObject {
protected:
    int x, y;

public:
    GameObject(int x, int y);
    virtual ~GameObject();

    virtual int getX() const;
    virtual int getY() const;

    virtual void update() = 0;
    virtual void draw(const Renderer& renderer, int r, int g, int b) const = 0;
};


#endif