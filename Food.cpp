#include "Food.h"
#include <ctime>
#include <algorithm>

Food::Food() {
    // 난수 생성기 초기화
    rng = std::mt19937(static_cast<unsigned int>(time(nullptr)));
    position = {0, 0};
}

void Food::spawn(const GameMap& map, const Snake& snake) {
    // 맵 크기에 맞는 분포 설정
    std::uniform_int_distribution<int> distX(1, map.getWidth() - 2);
    std::uniform_int_distribution<int> distY(1, map.getHeight() - 2);
    
    const auto& snakeBody = snake.getBody();
    
    // 뱀의 몸과 겹치지 않는 위치 찾기
    do {
        position.x = distX(rng);
        position.y = distY(rng);
    } while (
        map.isWall(position) || 
        std::find_if(snakeBody.begin(), snakeBody.end(),
            [this](const Point& p) { return p == position; }) != snakeBody.end()
    );
}