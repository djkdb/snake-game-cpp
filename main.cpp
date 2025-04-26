#include "Game.h"
#include <iostream>
#include <cstdlib> // system() 함수 사용

int main() {
    // 콘솔 설정
    system("cls");  // 화면 지우기
    system("title 스네이크 게임");  // 콘솔 창 제목 설정
    
    // 게임 시작 안내
    std::cout << "===== 스네이크 게임 =====" << std::endl;
    std::cout << "조작 방법:" << std::endl;
    std::cout << "W: 위, A: 왼쪽, S: 아래, D: 오른쪽" << std::endl;
    std::cout << "ESC: 게임 종료" << std::endl;
    std::cout << "아무 키나 누르면 시작합니다..." << std::endl;
    
    _getwch();
    system("cls");
    
    // 게임 객체 생성 및 실행
    Game game(30, 20);
    game.run();
    
    return 0;
}