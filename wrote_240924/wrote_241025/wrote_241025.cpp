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


// DeltaTime
// void APlayer::Tick(float _DeltaTime)
// (Tick의 인자로 들어가거나 인자에 곱해서 사용...)
// Engine이 제공하는 
// 
// 프레임수가 다르더라도 그에 대하여 시간에 대한 행위수를 맞춰줄 수 있다.
// 
// 
// #include <Windows.h>   (OS에서 제공하는...시간 재는 기능)
// 
// ns단위로 시간을 잴 수 있다. 
// QueryperformanceCounter ... 초당 몇번?
// QueryperformanceFrequency ... 여태까지 몇번 실행?
// 위의 두 함수를 이용해서 시간을 알 수 있다.
// 
// #include <chrono>   (std)
// 
// TimeCheckStart();
// TimeCheck ();       앞으로 이 둘을 넣어서 시간을 잰다. (ns 나노 sec)
// 
// 그러나 정밀하게 시간을 잴 수록 값의 크기가 급격하게 커진다.
// int는 금방 over하니 8바이트 정수가 필요하다.
// 
// void UEngineAPICore::Tick()
// {time_t Test = time(nullptr); 
//  현재 시간을 잰다.
// }
//

// (Long == int ...int와 거진 같다.)
// long long은 __int64

//094_Union
// 같은 위치에 여러개의 이름을 붙이는 문법
// 
// 형변환이 필요 없게된다.
// 
// Union Test
// {
//  public:
// 
// }
// 
// 
// inner unamed struct
//  
// 
// 
// (C에서 union을 쓰기 위해 typedef union large_interger를 쓴 것일뿐)
//
//

union Test
{
    int Value0 = 1;
    float Value1;

    //이렇게 하고 Value1 값을 확인하면 깨진다.
    //형변환이 필요하다.

};

//float은 실수다.
//소수점 이하를 표현한다.
//문제는 연산에서 오차가 생긴다. 따라서 비교연산이 의미가 없어진다. (== 등등)
//

//double
// 8바이트 실수
// 이진법으로 표현했을 때 특정 비트(소수점 비트)를 기준으로 정수부분과 소수부분을 나눈다.
// 
// 실수에 f를 안 붙이면 double형(8바이트), f붙이면 float형 실수(4바이트)가 된다.
// 만약 float에 double을 넣으면 연산을 통해 float으로 변환시키기 때문에 느려지게 된다. 
//