// wrote_241111 M.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// (API)
// 
// Collision 전, 중, 후
// (단, 그룹과 그룹의 충돌 함수를 호출하지 않으면 절대 호출 안 됨.)
// Tick처럼 계속해서 충돌을 했는지 체크한다.
// 
// 전: 처음 닿았을 때 딱 한번 호출
// SetCollisionEnter();
// 
// 중: 계속 닿고 있을 때 호출되는 함수
// SetCollisionStay();
// 
// 후: 계속 닿고 있을 때 호출되는 함수
// SetCollisionEnd();
// 
// 
// (Enginecore, U2Dcollision)
// functional 사용
//                                     충돌한 상대
// void SelCollisionEnter(std::function<void(AActor*)> _Function)
// void SelCollisionStay(std::function<void(AActor*)> _Enter)
// void SelCollisionEnd(std::function<void(AActor*)> _Enter)
// 
// ULevel은 충돌체를 가지고만 있을 뿐
// 충돌 체크를 하진 않는다.
// std::map<int, std:;list<>> Collisions;
// 
// 어떤 그룹과 그룹이 충돌하는지 기록해놓은 자료구조
// static std::map<> CollisionLink
// 
// 이벤트를 셋팅한 것들만 추려서 충돌 체크하게 만들겠다.
// 
// (Player)
//                                                  플레이어는                몬스터와   
// GetWorld()->CollisionGroupLink(ECollisionGroup::PlayerBody, ECollisionGroup::Monster ); 충돌한다.
// 위를 호출해야 이벤트가 시작된다.
// 데미지 판정...항상 체크 중인 위 방식을 통해서 한다.
// Collisioncomponenet->SetCollisionEnter();
// 
// (ULevel)
// CollisionLink 
// monsterbodyfmf 
// 
// 이벤트 ... 매 프레임 마다 체크 
// void U2DCollision::
// pushCheckCollision
// 
// 어디서 호출하건 상관없다. 
// static void collisionGroupLink(int _Left, int _Right)
// {
//    좀 별로지만 vector
// }
// 
// CheckCollision
// 
// 그리고 Release도 만든다.

// void CollisionEventCheck(_Left, _Right);
// 
// 충돌 이벤트 방식
// 충돌했을때 이전에 충돌했는지 확인해야 한다.
// 최초 충돌시 충돌대상의 주소값을 저장. 그리고 다시 충돌했을 때 주소값이 존재한다면 Stay() 호출.
// 충돌 종료시 내부의 주소값 삭제하고 End() 호출
// 
// 
// std::set, value가 없는 map
//
