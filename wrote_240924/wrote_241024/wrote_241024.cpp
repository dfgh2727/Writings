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
// 최신방식의 주의점, 내부에 노드가 없으면 만들어버림(push_back)
// 
// 레벨 이름이 틀리면 터지게 만들었다.
// 
// 레벨을 만들여면 게임모드를 먼저 지정해야 한다.
// GUI 에디터가 없으므로 저장했다가 읽어서 코드로 친다.
// 
// 이미지 하나가 액터 하나.
//
// (PlayGameMode.cpp) APlayGameMode::BeginPlay()
// 메인 플레이어를 지정하는 방식으로 설정!
// 따라서 spawnActor로 player를 불러낼 필요 없다.
// 단, 순서를 잘 생각하고 코드를 짜야 한다.
// 주인공과 기타등등의 등장순서는 코드에 의해 결정된다.
// 
// (Level.h) void CreateGameMode()
// 
// AllActor list로 동적할당 했으니 delete 해주고.
// (최신 방식이 있지만 방법을 잊지 말라는 의미로 Iterator로 지웠다.)
// 
// (Level.cpp) Tick과 Render
// 원래 AActor는 render되지 않지만 일시적으로 만들고 지움.
// 

//EngineMath
// :
// *수학적인 것도 PreCompile에 넣는게 편하다*
//
// ZERO 원점
// 
// 기본 크기 없음! 크기 정해줘야 한다.

//WinAPI 기본 렌더링의 핵심
//
// HDC
// window창에 그리기 위한 권한 핸들.
// 이미지인 동시에 그 이미지의 수정 권한.
// 한 윈도우 창에 한 개의 (윈도우와 연결된)Main HDC만 존재한다.
// 보통 이걸 BackBuffer라고 한다.
// 
// 무언가를 그리는 함수가 요구하는 첫번째 인자는 HDC.
// 
// 
// 윈도우 좌표
// 
// (0,0)
//      ---------------
//     |               |
//     |               |
//     |               |
//      ---------------  (1280, 720) 
// 
//  Rectangle ( x1, y1, x2, y2)
// 
// static이 아니니까, 
// UEngineAPICore:: GetCore -> GetMainWindow
// 
// Void AActor::Render()
// 
// Actor를 render하면 GameMode도 render되니까 안 좋다.
// (GameMode를 render될 필요는 없으니까)


//093_Dynamic Cast
// 
// 부모자식 관계일 때 호출하는 캐스트
// vptr 기반으로 동작한다.
// 
// 업캐스팅일 때는 암시적으로 형변환이 잘 되고 안전하기에
// 굳이 명시적으로 쓰지 않는다.
// 따라서 보통 부모형을 자식형으로 바꿀 때 쓴다. 
// 
// 클래스의 부모 중 누구도 virtual이 없는 상황이라면 캐스팅을 못한다고 에러가 뜬다.
// (다형 클래스... virtual이 있는 클래스)
// 그래서 정 virtual을 붙일게 없다면 소멸자에 붙인다.
// (차피 소멸자에 붙여야 자식의 소멸자가 호출되기 때문에...)
// 
// 안전하게 자식형으로 캐스팅 할 수 있다.
// 캐스팅을 잘못하면 nullptr을 리턴.
// 
// 가장 느린 캐스팅으로 알려져 있다.
// 


//만들 때 Release로도 빌드가 잘 되는지 꼭 확인!


