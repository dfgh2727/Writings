// wrote_241120 W.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// (SpriteRenderer.cpp)
// HPbar 만들다가 Pivot 만지기...;;;
// 
// Pivot {0.5, 0.5} 은 center ({1, 1}을 전체 크기로 생각)
// 
// 
// SetPivotValue()를 통해 직접 Pivot값을 정해줄 수도 있다.
//
// float으로 인해 생기는 오차를 버리자. floorf
// 떨리는 현상 제거...
//
