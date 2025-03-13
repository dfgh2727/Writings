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
//	  if(nullptr == GetWorld()->GetAuthMode())
//	  {
//		 SyncServer(); 
//		 클라이언트가 준비되었을 때 
//		 서버에 접속된 다른 플레이어의 캐릭터를 동기화한다.
//    }
// }
// 
//
// 

// 
// 
// 
// 
// 
