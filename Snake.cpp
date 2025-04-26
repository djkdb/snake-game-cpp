#include "Snake.h"

Snake::Snake(int x, int y) {
    body.push_back({x, y});
    direction = RIGHT;
    isGrowing = false;
}

void Snake::move() {
    // 방향에 따른 다음 좌표 계산
    Point nextHead = body.front();
    
    switch (direction) {
        case UP:    nextHead.y--; break;
        case RIGHT: nextHead.x++; break;
        case DOWN:  nextHead.y++; break;
        case LEFT:  nextHead.x--; break;
    }
    
    // 새로운 머리 위치 추가
    body.insert(body.begin(), nextHead);
    
    // 성장 중이 아니면 꼬리 제거
    if (!isGrowing) {
        body.pop_back();
    } else {
        isGrowing = false;
    }
}

void Snake::grow() {
    isGrowing = true;
}

// Snake.cpp 에 추가
bool Snake::isSelfCollision(const Point& nextHead) const {
    for (const auto& segment : body) {
        if (segment == nextHead) return true;
    }
    return false;
}


void Snake::changeDirection(Direction newDir) {
    // 현재 방향의 반대 방향으로는 이동할 수 없음
    if ((direction == UP && newDir == DOWN) ||
        (direction == DOWN && newDir == UP) ||
        (direction == LEFT && newDir == RIGHT) ||
        (direction == RIGHT && newDir == LEFT)) {
        return;
    }
    
    direction = newDir;
}