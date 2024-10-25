// wrote_241025.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// !!인터페이스 변경은 절대 금지!!
// 엔진 변경하지 말기
// 인자를 늘린다던가, 함수를 없앤다던가... (함수를 늘리는건 괜춘)
//

// 프로그램은 focus 되어 있지 않아도 계속 루프를 돈다.
// 루프 돌기 전에 레벨을 만든다.
// 
// Level.h
// (private)
// Level이 가동하기 전에 MainActor와 GameMode가 반드시 먼저 생성된다.
// 또한 템플릿으로 설정해서 GameModeType을 정할 수 있게 만들었다.
// (플레이 게임 모드, 타이틀 게임 모드 등...)
// 
// 사실 주인공(MainPawn)은 화면이 보이는 기준, 즉 카메라 처럼 생각하면 된다.
// (스킬이나 능력을 직접 넣는 생각은 지양하는게 좋다.)
// 
// SpawnActor는 ULevel이 가지고 있다.
// 스폰되려면 자기 자신을 만든 Level을 알고 있어야 한다.
// 근데 World를 바꿀 수 있으면 안된다. GetWorld로 접근
// 
// vector에 push_front는 없다. 엄청난 부하가 걸리기 때문에...
// Level을 어떻게 하면 가장 안전하게 바꿀 수 있나...
// 
// 
// PlayGamemode.cpp
// void BeginPlay()
// 
// 진짜 동작하는 Level에 대한 ptr, CurLevel
// 
// 당장 UserCore는 의미가 없다. 
// 
// MainCore 
//

//게임에서 무슨 Actor가 등장해야 하나...
// List화 해보기.
// 
// 가령 타이틀에 보이는 Actor가 존재한다면
// 
// class TitleLogo : public AActor
// {
// };
// 
// 

// 언리얼...오픈 소스다. 직접 코드를 뜯어 고칠 수 있다.


//void EngineTick()
// 
// 이 함수가 1초에 몇번 실행 되는가가 곧 프레임이다.
// 프레임수에 의해 행위 횟수가 결정되면 곤란하다.
// ...DeltaTime으로 해결하자!
// 
// DeltaTime
   void APlayer::Tick(float _DeltaTime)
// (Tick의 인자로 들어가거나 인자에 곱해서 사용...)
// Engine이 제공하는 
// 
//
//
//