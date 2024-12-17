// wrote_241216.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 콘솔창
// 코드를 치지 못하는 사람들을 위한 창
// 콘솔창을 띄워보자.
// 
// #include <Windows.h>
// AllocConsole();
// FreeConsole();
// 
// window라는 개념을 가진 창(Window OS가 관리하는)에는 입출력 버퍼가 존재한다.
// 명령을 내릴 수 있는 핸들을 의미한다.
// console도 핸들과 같은 권한을 얻어야 한다.
// 
// #include <tchar.h>
// _tfreopen_s();  콘솔창과 연결된 입출력 핸들을 내가 지정한 것으로 바꾼다
// (_tfreopen로 쓸 수도 있으나 옛날 방식이고 경고가 뜰 수 있다.)
// 
// _tfreopen(_T("CONOUT$"), _T("w"), stdout); (= 콘솔창의 기본 출력 버퍼를 stdout이라는 것으로 변경)
// _tfreopen(_T("CONIN$"), _T("r"), stdin);
// _tfreopen(_T("CONERR$"), _T("w"), stderr);
// ... 그러나 위 내용이 통하지 않는다. 이유가 뭘까.
// 
// 입출력 버퍼란?
// 윈도우 창에서 입출력 버퍼를 HWND가 알아서 관리해주지만...
// CONOUT$ 출력버퍼, CONIN$ 입력 버퍼를 의미
// 
// pCout은 옛날식 출력 버퍼. stdout은 현재 스타일.
// 둘이 다르지 않다. (if(pCout ! = stdout)의 내용의 코드가 실행되지 않음)
// 
// 여차저차 콘솔창을 띄우는 구조를 만들었다.
// 

// IContentsCore
// (UEngineLevel을 ULevel로 수정했다.)
// 
// template <typename GameModeType,typename MainPawnType> 
// class ULevel* CreateLevel();
// 위 구조는 이전과 동일하게,
// 
// (Api에선 싱글톤 방식으로 GetCore()로 접근했으나...이젠 안 쓰겠다. 객체화 하지 않고 static으로 간다.)
// static std::map<std::string, std::shared_ptr<> >
// 
// Levels.clear();
// 이 때 레벨이 다 삭제되어야 한다.
// 
// 이제 ULevel은 shared_ptr로 관리한다.
// std::shared_ptr<ULevel> NewLevel = std::make_shared<ULevel>();
// make shared 대신 new를 직접 쓸 수 있으나 shared_ptr을 쓸 경우 권장하는 구조는 위의 것이다.
// 
// std::shared_ptr<ULevel>
// 
// .h에 헤더를 추가할 땐 주의. 순환참조할 위험이 있다.
// .cpp는 상관없다.
// 
// shared_ptr을 사용할 시 레퍼런스 카운트를 잘 생각해야 한다. 
// 현재 map안에 있어서 카운트가 2다.
// 
// CRTDBG는 데이터 영역의 일정 부분까지만 확인한다.
// static...데이터 영역에 존재하므로 leak이 남는걸로 판단할 수도 있다.
// 따라서 shared_ptr을 쓰더라도 지워지는 것을 하나씩 확인한다. -> Level이 어떻게 지워지는지 확인하고 가자.
// 
// static은 this가 없다.
// 

// 충돌은 인터페이스 변함없이.
// FTransform은 대거 편집된다. 이제는 3D니까.
//
// 중간과정을 다 보라는 의미로 FMatrix의 내용을 전부 따로 만들었다.
// (원래는 한번에 다 곱하기 때문에 FMatrix WVP로 만든다.)
// 
// .
// .
// .
// 
// AActor
//
// 언리얼에서 Actor는 트랜스폼을 가지지 않는다.
// 컴포넌트 구조상 위치와 같은 값은 가지지 않는다.
// 
// Transform을 가지는 컴포넌트는 USceneComponent 뿐이다.
// TObject<USceneComponent> RootComponent; (언리얼)
// RootComponent를 상속받을 뿐.
// 
// SceneComponent와 ActorComponent를 분리해서 관리한다.
// 
// 부모 자식 관계에서 로컬.
// 자식의 월드(실제)값이 아닌 부모를 기준으로 가지는 값.
// 언리얼에선 Relative라고 한다.
// 
// 자식은 부모의 모든 값을 물려받는다. (크기, 위치 등...)
// 즉, 부모가 커지면 자식도 커진다.

// Level의 Actor 관리 기능...
// std::shared_ptr<ActorType> SpawnActor()
// 템플릿은 일종의 복붙이니까
// 
// std::list<std::shared_ptr<class AActor>> BeginplayList;
// std::list<std::shared_ptr<class AActor>> BeginplayList;
// 
// 언리얼에선 GameMode는 GameModeBase를 상속받는다.
// 우린 AActor를 상속받도록 만든다.
// 그리고 AActor는 BeginPlay와 Tick을 가진다. (virtual)
//
// Level에서 SpawnActor로 Actor를 불러낸다.
// UEngineCore에 "Level.h" 추가.
// 
// ULevel::Tick(flaot _DeltaTime)
// : ...BeginPaly에 있다가 AllActors로 이동한다. 
// 
// 주인공 캐릭터는 무조건 APawn을 상속 받는다.
// class Pawn : public AActor
// 
// 다른 .h에 PreCompile.h를 넣으면... 엄청난 순환참조 발생
// 절대 하지 말기. cpp에나 넣으렴.
// 
// IsActive()... ranged for는 바꾸지 않으면서 전부 돌려준다는 의미니까 내부에서 수정이 불가능하다.
// 따라서 Iterator를 사용한다. 
// 
// UEngineCore에 EngineFrame, EngineEnde()을 만든다.
// EngineFrame안에 Tick이 있고, LevelChange()가 호출되면 Level이 교체된다. 
// CurLevel->LevelChangeStart()
// 
// CurLevel이 아니라 NextLevel을 바꾸는 방식.
// Tick을 돌던 와중에 Level이 바뀌면 곤란하니까.
// 
// 이젠 Super가 아니라 부모를 직접 호출해야 한다.
// void ATempGameMode::Tick(float _DeltaTime)
// {
//     AActor::Tick(_DeltaTime);
// }
// 
// GetWorld()가 있어야 했던 이유?
// 
// ULevel* World;
// 아무나 SetWorld를 하면 안 된다.
// friend class ULevel 선언.
// 
// Level이 만들어지지 않은 Actor는 만들어 질 수 없다.
// Actor가 만들어져야만 Level이 세팅될 수 있다.
// 힙 영역에 sizeof(AActor)를 만단다. 
//

// 언리얼에선 std 함수 안 쓴다. (vector, map, shared_ptr 등...)
// TObjectPtr은 언리얼의 shared_ptr.


//101_reNew (placement new)
// 
// C는 class는 없어도 구조체는 있다.
// malloc() ...원하는 크기의 메모리 영역을 힙에서 할당
// 
// 가상함수 테이블... 컴파일러의 몫이다.
// 값만 있다고 생성자 없이 호출한다면...가상함수 테이블이 제대로 만들어지지 않아 생성자가 호출되어야 한다.
// __vfptr을 만들기 위해.
// -> placement new
// 
// 

// 기소서
// :면접관의 질문을 유도하기 위한 자료
// 
// 사용한 자료구조 무조건 넣기 (vector, map, list...)
// 자료구조를 사용한 이유 추가.
// 
// 디버깅 내용 추가 (디버깅 기능들에 대한 내용)
// (면접관들이 제일 좋아한다)
// 
// FTransform, UCollision2D에 대한 설명 (충돌에 대한 정확한 설명)
// FTransform에 어떤 기능들이 있는지, 무엇을 위해 넣었는지(편의성을 위해)
// virtual...상속구조, 상속내린 모든 기능에 대해서 설명
// 왜 상속을 넣었는가에 대해 설명해야 한다.
// 
// 관리한 방법 (AActor, UI...)
// 
// 코드 많이 넣지 말기
// (차피 보이지 않으면 의미도 없다)
// 
// 게임의 기획적인 내용은 한두페이지만. 그리고 기술적인 설명 추가.
// 예) ~한 레벨들이 있다. -> ...충돌방식을 통해서, LevelChangeStart()...
// 
// 함수 선언들을 넣어라. 함수 내용은 너무 길다.
// 만약 묶여있지 않다면 아예 함수를 만들어라.
// 
// 소제목을 달아주자. 
// 
// 컨텐츠의 핵심 클래스에 대한 설명, 핵심 인터페이스(2~3개 정도)에 대한 설명
// CatMario, 함수들...
// 
// gif 넣지 말기
//
