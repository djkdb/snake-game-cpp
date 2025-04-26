#pragma once
#include <vector>
#include "Point.h"

class GameMap {
private:
    int width;
    int height;
    std::vector<std::vector<char>> map;

public:
    GameMap(int w, int h);
    void initMap();
    void drawWalls();
    void clear();
    void setPoint(const Point& p, char value);
    char getPoint(const Point& p) const;
    void render() const;
    bool isWall(const Point& p) const;
    int getWidth() const { return width; }
    int getHeight() const { return height; }
};