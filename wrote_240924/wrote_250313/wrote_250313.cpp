// wrote_250313.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// 동기화
// 
// 몬스터를 동기화 해보자.
// 몬스터의 Tick에서 multicast 함수를 사용하는 것은 좋지 않다.
// 대략 초당 60번 정도 패킷을 전송하게 되는데, 서버에 주는 부담이 매우 커진다. 
// 어디에서 실행시켜야 할까?
// 
// 보통 만들어진 클래스는 자료구조로 관리한다. 
// 그리고 그 자료를 Manager클래스(UActorComponent)가 가지고 있다.
// Manager클래스에 component replicate를 설정한다.
// 
// void UMonsterManager::NetsyncMonster()
// {
//	  for()
//	  {
//		int CurAnimation = AllMonster[i]->
//		AllMonster[i]->ChangeAnimation_Multicast(CurAnimation);
//		(for문을 돌면서 몬스터에 대해 NetMulticast 함수를 실행한다.)
//    }
// }
// 
// 블루프린트의 BeginPlay이벤트는 Super::BeginPlay()에서 실행된다.
// BeginPlay에서 함수를 실행시킬 때 위 사실을 기억하고 순서에 유의하여 코드를 작성해야 한다.
// 
// 그리고 플레이 가능한 캐릭터 입장에서 몬스터의 동기화는 다음과 같다.
// void APlayCharacter::BeginPlay()
// {
//	  Super::BeginPlay();
//	  
//	  클라이언트가 준비되었을 때 동기화한다.
//	  if(nullptr == GetWorld()->GetAuthMode())   
//	  {
//		 SyncServer(); 
//    }
// }

// 최적화
// 
// 렉이 걸리는 이유는 
// 한번에 모든 캐릭터가 무거운 연산을 해서 느려지기 때문이다.
// 
// 가령 몬스터가 탐색을 실행하는 경우,
// 매 프레임마다 탐색을 실행할 필요가 없으니 Tick 간격을 늘이자. 
// 그리고 모든 몬스터가 같은 프레임에 탐색을 실행하기 보다 각자가 다른 시점에 실행하는 것이 좋다. 
// 

// 언리얼의 deligate
// 
// 일반 함수 포인터와 뭐가 다르지?
// deligate는 언리얼의 규칙을 따른다.

