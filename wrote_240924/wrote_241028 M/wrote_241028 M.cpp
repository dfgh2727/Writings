// wrote_241028 M.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

//엔진을 사용할 떄 기능을 직접 만들지 말고 엔진이 제공하는 기능을 써야한다.
//
// 1. 컨텐츠를 많이 사용한다.
// 2. 엔진이 업데이트 되면 만들어 둔게 무너진다. 
// 
// 직접 만들어야 한다면...OS인지 std인지 따져야 한다.
// 1. 기본적으로 하드웨어에 관련된 것은 대부분 OS
// 2. 문법적인 측면에서 접근하는 경우는 std
// 
// 엔진을 랩핑하는 대표적인 방법
// (EngineWindow가 우리 엔진의 대표적인 랩핑 클래스다.)
// WinAPI 기능을 공개하는 경우는 없다.
// 
//

//(API)
// 
// 필수 라이브러리 함수들을 native function이라고 한다.
// 
// window의 타이틀을 바꾸는 함수...있다.
// SetWindowTectA();
// 당연히 인자는 핸들(HWND)이다.
// 
// RAM에 위치한 OS와 나의 프로그램...
// 윈도우창 메모리는 OS에 생기고 그에 대한 포인터(핸들)가 내 프로그램에 생긴다.
// 
// ContentsCore에서 SetWindowTitle에 접근하게 만들었다. 
// 
// Player.cpp
// 입력...키보드를 관리하는 OS를 통해서 실행
// 윈도우가 제공하는 기본 입력함수를 사용
// 
// 입력 버퍼는 윈도우가 알아서 처리하기 때문에 
// 입력이 있을 때만 0이 아닌 수를 처리한다.
// GetAsyncKeyState()
// 
// (키의 압력은 무시하자. 오래 눌렀다는 체크 가능)
// 
// EnginePlatform
// (Input)
// class UEngineInput 생성자를 private로 만들었다.
// 

//Singleton
// 디자인 패턴 (관리패턴, 생성패턴, ...)
// 
// 싱글톤, 단 하나의 instance를 만드는 패턴. (by 갱오브포)
// 객체를 프로그램 통틀어서 단 1개만 만든다.
// 보통 static과 함께 쓴다.
// 클래스 자기 자신이 만들어서 외부에 공개한다.
// 
// 크게 포인터형과 값형으로 나눈다.
// 포인터형의 장점, 지울 수 있다. 한 쌍의 삭제함수를 무조건 만들어야 한다.
// 
// 값형으로 진행한다. 
// (굳이 지울 필요 없으니까...)
// 클래스 내부 즉, 지역 Static 선언.
// 

//097_Local Static (지역 static)
//
// 어떤 전역변수를 특정 함수에서만 사용하고 싶을 때 선언
// 전역변수처럼 값이 유지된다.
// (만약 전역변수를 선언하면 누구나 사용 가능하기 때문에 바깥에서 못 쓰게 막는 방법)
// 

// (API)
//
// 값형 싱글톤은 만들기 쉽다.
// 
// UEngineInput, UEngineKey
// 
// private:
// class UEngineKey (외부에 공개 ㄴㄴ)
// 
// UEngineInput.cpp
// UEngineInput()에 키를 등록해야 사용 가능하다.
// (VK_... 찾아보면 키들이 있다.)
// 
// Map으로 만들고 (puch_back이 아닌 insert)
// if 등록되지 않은 키를 입력하면 터진다.
// 
// vector나 list를 쓸 때 에러가 나면 출력창 맨 위를 보자.(F8을 누르거나...)
// 
// Keys[_KeyIndex]가 없으면 node를 만든다.
// 그리고 내용이 빈 생성자가 없어서 에러가 난다.
// 
// Player.cpp
// 버튼이 눌린 한 순간만 체크하는 기능이 필요하다.
// UEngineInput::KeyCheck()
// Iterator로.
// 명시적이게 한번 받아주는 코드 작성.
// 
// void UEngineInput::
// 함수가 옛날 C스타일로 작성... bool값이 없으니 0!으로 if 문 작성
// 플랫폼(조이스틱, 키보드...)에 따라 입력 키가 변하므로 Platform에 위치
// 
// 게임
// 
// BindAction 
// 어떤 키를 눌렀을 때 복수의 event 발생을 위해.
// 
// enum class KeyEvent
// 
// KeyCheck(_DeltaTime)
// void APlayer
//
// Player.cpp
// 움직일 때 DeltaTime이 필수는 아니니 인자에서 뺀다.
// GetDeltaTime으로 DeltaTime을 가져다 쓰자.
// 
// 인자 없는 함수만 불러내게 만들었다. 
// Movefunction으로 쓰는 함수는 동일, 벡터로 방향만 다르게
// 

// (API) 렌더링에 대해 살펴보자
// 
// BackGround는 GameMode에서!
// 컨텐츠용 게임모드, 레벨이 만들어지면 무조건 만들어져야 한다.
// 게임모드는 레벨마다 만들어야 한다. 그리고 가장 먼저 만들어져야 한다.
// 
// 더블 버퍼링
// 크기가 같은 무언가가 화면 위를 완전히 덮는다면... 지워지고 뜨는 과정을 반복해도
// 느껴지지 않는다. 
// 하나의 화면에 모든걸 그리고 그걸 띄운다.
// 
// HDC를 만들어서 거기에 열심히 그려도
// 윈도우 창과 연결되지 않으면 화면에 뜨지 않는다.

// EngineWindow.h
// 윈도우창의 크기를 지정하는 함수를 쓰자.
// void UEngineWindow::SetWindowPosAndScale()
// 윈도우창 타이틀을 제외하고 계산한 크기로 설정하는 함수 사용
// AdjustWindowRect()
// 
// (만약 창의 스타일을 바꾸고 싶다면 common window style을 확인하자. 난 안 함.)
//
// 윈도우창 몸통을 시작점으로 두기 때문에 설정을 안 할 시 LeftTop이 음수값이 된다.
// 그리고 테두리도 크기에 포함되어 있으니 
// 따라서 창이 뜨는 위치(Pos)를 right-left, bottom-top 으로 설정해야 한다. 
// 
// HDC를 이제 2개 만든다. (BackBufferDC, WindowMainDC)
// 그리는건 WindowMainDC에 그리고 BackBufferDC는 그걸 복붙한다.
// 
// void Create(HDC _DC) (load와 같은)
// 
// PlayerImage를 WindowMainDC에 복붙(Copy),
// {(위치), (크기), PlayerImage}
// 윈도우 창의 크기를 정해야지 BackBuffer의 크기도 정해진다.
// void UEngineWindow::SetWindowPosAndScale()
// {
//     
// }
// 
// 그리고 BackBuffer가 여러번 호출되지 않도록 기존의 것을 삭제하고 새로 만들게 한다.
// if (nullptr!= BackBufferDC)
// {
// }
// 
// CreateconpatibleBitmap()
// 
// HDC만 있어서는 이미지를 그릴 수 없다.
// HDC는 이미지 그 자체(HDC Image)
// 
// 이미지 = 이미지를 수정할 수 있는 권한(HDC) + 이미지의 데이터 권한(HBITMAP)
//                                  그린다                          도화지
// 
// 붓과 도화지를 연결해주자.
// SelectObject(NewImageDC, NewBitmap);
// 
// HDC를 만들면 Window OS가 자동적으로 1x1 이미지와 연결해 놓는다.(OldBitMap)
// 따라서 삭제하지 않으면 leak이 발생한다.
// DeleteObject(OldBitMap)
// 
