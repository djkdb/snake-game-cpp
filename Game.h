#pragma once
#include "GameMap.h"
#include "Snake.h"
#include "Food.h"
#include <string>

class Game {
private:
    GameMap map;
    Snake snake;
    Food food;
    bool gameOver;
    int score;
    int speed;

public:
    Game(int width, int height);
    void run();
    void handleInput();
    void update();
    void render();
    bool isGameOver() const { return gameOver; }
    void displayGameOver() const;
    int getScore() const { return score; }
};