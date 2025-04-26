#include "GameMap.h"
#include <iostream>
#include <windows.h> // Windows 콘솔 조작용

GameMap::GameMap(int w, int h) : width(w), height(h) {
    map.resize(height, std::vector<char>(width, ' '));
    initMap();
}

void GameMap::initMap() {
    clear();
    drawWalls();
}

void GameMap::drawWalls() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                map[i][j] = '#';
        }
    }
}

void GameMap::clear() {
    for (auto& row : map) {
        std::fill(row.begin(), row.end(), ' ');
    }
}

void GameMap::setPoint(const Point& p, char value) {
    if (p.x >= 0 && p.x < width && p.y >= 0 && p.y < height)
        map[p.y][p.x] = value;
}

char GameMap::getPoint(const Point& p) const {
    if (p.x >= 0 && p.x < width && p.y >= 0 && p.y < height)
        return map[p.y][p.x];
    return '#'; // 맵 밖은 벽으로 간주
}

void GameMap::render() const {
    // 커서를 콘솔 상단으로 이동
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    for (const auto& row : map) {
        for (const auto& cell : row) {
            std::cout << cell;
        }
        std::cout << std::endl;
    }
}

bool GameMap::isWall(const Point& p) const {
    return getPoint(p) == '#';
}