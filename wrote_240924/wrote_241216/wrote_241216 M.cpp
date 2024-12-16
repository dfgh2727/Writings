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
// _tfreopen(_T("CONOUT$"), _T("w"), stdout);
// _tfreopen(_T("CONIN$"), _T("r"), stdin);
// _tfreopen(_T("CONERR$"), _T("w"), stderr);
// 
// (-- 잠깐 보류 --)

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
// FTransform은 대거 편집된다.
// 

// AActor
//
// 기하 구조를 생각해보자!
// 
//