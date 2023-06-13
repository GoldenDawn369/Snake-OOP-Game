#include "GameObject.h"

GameObject::GameObject(int x, int y) : x(x), y(y) {
}

GameObject::~GameObject() {
}

int GameObject::getX() const {
    return x;
}

int GameObject::getY() const {
    return y;
}
