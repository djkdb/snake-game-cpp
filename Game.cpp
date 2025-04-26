#include "Game.h"
#include <iostream>
#include <conio.h> // _kbhit() 및 _getch() 함수 사용
#include <windows.h> // Sleep() 함수 사용

Game::Game(int width, int height) 
    : map(width, height), 
      snake(width / 2, height / 2), 
      gameOver(false), 
      score(0),
      speed(100) {
    
    food.spawn(map, snake);
}

void Game::run() {
    // 초기 화면 렌더링
    render();
    
    while (!gameOver) {
        handleInput();
        update();
        render();
        Sleep(speed); // 게임 속도 조절
    }
    
    displayGameOver();
}

void Game::handleInput() {
    if (_kbhit()) {
        char key = _getch();
        
        switch (key) {
            case 'w': snake.changeDirection(UP); break;
            case 'd': snake.changeDirection(RIGHT); break;
            case 's': snake.changeDirection(DOWN); break;
            case 'a': snake.changeDirection(LEFT); break;
            case 27: gameOver = true; break; // ESC 키
        }
    }
}

void Game::update() {
    // 1. 이동할 다음 머리 위치 계산
    Point nextHead = snake.getHead();
    switch (snake.getDirection()) {
        case UP:    nextHead.y--; break;
        case RIGHT: nextHead.x++; break;
        case DOWN:  nextHead.y++; break;
        case LEFT:  nextHead.x--; break;
    }

    // 2. 벽 또는 자기 자신과 부딪히면 즉시 게임 오버
    if (map.isWall(nextHead) || snake.isSelfCollision(nextHead)) {
        gameOver = true;
        return;
    }

    // 3. 안전하면 실제 이동
    snake.move();

    // 4. 먹이 먹었는지 체크
    const Point& head = snake.getHead();
    if (head == food.getPosition()) {
        snake.grow();
        score += 10;
        
        food.spawn(map, snake);
    }
}


void Game::render() {
    // 맵 초기화 (벽만 유지)
    map.initMap();
    
    // 먹이 그리기
    map.setPoint(food.getPosition(), '*');
    
    // 뱀 그리기
    for (const auto& segment : snake.getBody()) {
        map.setPoint(segment, 'O');
    }
    
    // 맵 렌더링
    map.render();
    
    // 점수 표시
    std::cout << "점수: " << score << std::endl;
}

void Game::displayGameOver() const {
    std::cout << "게임 오버! 최종 점수: " << score << std::endl;
    std::cout << "아무 키나 누르면 종료됩니다..." << std::endl;
    _getch();
}