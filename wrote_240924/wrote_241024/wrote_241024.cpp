// wrote_241024.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

//091
//
// 전역함수는 bind 생략 가능하다.
// 
//

//092 Delegate
// 
// operator += 추가해주는 연산자... push_back과 같다고 보면 된다.
//
//

// (API)
// 
// EnginePlatform에 시작+루프를 묶어줬다.
// EngineStart 이름이 겹쳐서 EngineBeginPlay로 이름 바꿈
// 
// EngineAPICore
// 

// static 초기화 하는거 잊지 말기!

// VS가 핸들은 정수로 처리하는걸 권장한다. C 스타일이라...

//Object 구조
// 
// 제공된 Level이란 클래스로 만들면서
// GameMode를 넣을 구조를 만들어야 한다.
//
// Level1 장면 ... 장면 전환을 구현
// 
// 엔진코어로  CreateLevel();
// 타이틀 ~ 플레이 ~ 엔딩
// 엔진코어 -> CreateLevel<TitleGameMode>();
// 엔진코어 -> CreateLevel<PlayGameMode>();
// 엔진코어 -> CreateLevel<EndingGameMode>();
// 
// Actor ... 레벨에서 등장하는 요소들 전체
// 
//
// class 
//
// 
// 맵 레벨, 플레이어 레벨, 몬스터 레벨, 타이틀레벨...
// world에서 작동시킨다. 레벨들을 합쳐서 작동이 가능하다.
// 
// 멤버함수의 이름은 대문자로 시작
// 
// APP main에 Levels.clear는 없어도 되지만 넣었다.


// Contents는 완전히 개인의 영역! 

//Main 에 있는 지역변수들... 사실 전역 선언해도 되지만 객체지향으로 만드느라;;
// 
// 콘텐츠 cpp를 보면 GetCore로 MainCore에 접근, 
//
// 
// createlevel은 일종의 예시다.
// 
// 레벨 담는 자료구조 ULevel에 map으로 만들었ㄷ
// 
//엔진과 컨텐츠 코어는 프로그램 실행동안 한번만 만들어지고 포인터를 이용해
//
//메인코어의 타이틀레벨(new)...포인터로 쓰겠지만, 소유자를 확실히 하는게 좋다.
// 즉, 누가 메모리를 삭제해주는가...
//컨텐츠 코어는 포인터를 가지고 있지만 관리하고 지워주는건 엔진코어.
// 엔진코어가 타이틀레벨(new)를 소유하고 있다.
// 
// 객체를 생성하는 함수...이걸 없이 만들면 의미가 없다.
// 
// 관리란 삭
// (level을 map에 넣고 관리)
//

//EngineAPICore.h
// Culevel 현재 돌아가는 레벨
// 
// level.h에 BeginPlay
// 
// 화면 지정을 안 하면 터뜨리게 만듦
// void UEngineAPICore::Tick()
// if (nullptr == CurLevel)
// {  터진다
// ...
// 
// OpenLevel
// 
// CurLevel = Levels[changeName]; ... 최신방식(찾아서 리턴한다.)
// or Iterator로 이용하는 방법 ...
//


