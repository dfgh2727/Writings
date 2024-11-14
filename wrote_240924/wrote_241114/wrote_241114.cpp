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

// 역재생 기능도 있다!

// Reset 변경사항
// 
// ResetLevel ... Level을 삭제하고 다시 만든다.
// 현재 CurLevel에서 플레이(Tick, Render...등을 돌리는 중)중에 delete 하면 터질 수 있다.
// 따라서 Level을 모아놓은 list에서 erase만 하고 새로 만든 레벨을 NextLevel로 지정한다.
// 그리고 NextLevel을 CurLevel로 지정한다.
//
