#pragma once
#include "Point.h"
#include "GameMap.h"
#include "Snake.h"
#include <random>

class Food {
private:
    Point position;
    std::mt19937 rng;

public:
    Food();
    void spawn(const GameMap& map, const Snake& snake);
    const Point& getPosition() const { return position; }
};