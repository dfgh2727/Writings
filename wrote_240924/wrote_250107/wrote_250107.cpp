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
// 대신 대문자로 전부 바꿔서(To Upper) 언리얼과 비슷한 인터페이스를 만든다. 

// 카메라를 먼저 만들어야 Renderer를 만들 수 있다는걸 명심하자.
// MSGASSERT("존재하지 않는 카메라에 랜더러를 집어넣으려고 했습니다.")
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
// 
// union:
// Sphere의 위치를 정하면 나머지 AABB와 OBB의 위치도 자동적으로 정해진다.
// OBB의 값을 셋팅하면 나머지 Sphere와 AABB 모두 셋팅된다.
// 
// 충돌 인터페이스 데이터...통일시켜서 OBB를 기준으로 만들었다.
// (CircleToCircle, RectToCircle, RectToRect 무엇이든)
// 
// !주의!
// Collision크기와 Image크기를 똑같다고 생각하면 안 된다.
// 
// ABS(absolute) = 절대값
// 
// Actor만 release 가능하다. 충돌체만 제거하는건 불가능하다.
// (언리얼은 플레이 중간에 Renderer를 release할 수 없다. 캐쉬적중률을 고려해서...)
// 
// TimeEventer 주의...Actor가 제거되면 TimeEventer도 작동할리 없다.
// Renderer는 SetActive()로 활성화/비활성화를 설정한다.
// 
// CreateDefaultSubobject()를 하지 않으면 엔진 구조에 편입되지 않아 실행될 수 없다.
// (Tick()이 돌아가지 않는다.)
// 
// 부모인 Actor가 삭제되면 actorComponent도 삭제된다.

// shared_ptr은 반드시 nullptr 처리를 해야 한다.