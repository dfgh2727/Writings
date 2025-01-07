// wrote_250107.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// 언리얼은 class들을 string으로 보관하고 관리한다.
// string을 빌드 전에 Hash화 작업으로 처리하고 구분한다.
// 

// 문자열...
// 
// 여차저차 map의 key로 string_view도 사용 가능하다.
// 

// 카메라를 먼저 만들어야 Renderer를 만들 수 있다는걸 명심하자.
// MSGASSERT("")
// 
// CollisionProfile을 만들어야 충돌 그룹을 만들 수 있다.
// GetWorld()->CreateCollisionProfile("Monster")
// 이번 프로젝트에서 레벨마다 적용해야 한다.
// 
// AABB 회전하지 않은 박스?
// 박스를 이루는 면의 노말 벡터들이 곧 X Y Z축과 일치하는 모양이다.
// 
// OBB 회전한 박스?
// AABB와 마찬가지로 박스를 이루는 세 면은 서로 수직이지만
// 해당 면의 노말 벡터가 X Y Z와 일치하지 않는 박스이다.
// (https://handhp1.tistory.com/6 )
// 
