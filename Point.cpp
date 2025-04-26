#include "Point.h"

// Point 구조체는 헤더 파일에서 모든 내용이 인라인으로 정의되어 있으므로
// cpp 파일에서 추가로 구현할 내용은 많지 않습니다.
// 그러나 필요에 따라 추가 메서드를 여기에 구현할 수 있습니다.

// 예를 들어, 추가 생성자나 유틸리티 함수들을 구현하려면:

// 기본 생성자 구현 (이미 헤더에 정의되어 있다면 불필요)
// Point::Point() : x(0), y(0) {}

// 좌표 이동 함수 구현 예시
// void Point::move(int dx, int dy) {
//     x += dx;
//     y += dy;
// }

// 거리 계산 함수 구현 예시
// double Point::distanceTo(const Point& other) const {
//     int dx = x - other.x;
//     int dy = y - other.y;
//     return std::sqrt(dx*dx + dy*dy);
// }