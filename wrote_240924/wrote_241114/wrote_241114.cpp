// wrote_241114.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// SpriteRenderer 버그 
// pushRenderer에서 렌더 구조에 편입된다.
// 그런데 2번 들어감... Tick이 두번 돌아서 빠르게 재생됨;;
// 
// SetOrder(int _Order)
// if (PrevOrder = Order)
// {
//     return; 
// }
// 위를 추가해서 일단 막음....
// 
// 원래는 uSpriteRenderer::Render(float _DeltaTime)에 있었던
// 애니메이션을 진행시키는 코드를 Component Tick으로 옮겼다.
// 
//U2DCollision::Collision()
//U2DCollision* ThisCollision = this; 코드 위치 이동....
// 

