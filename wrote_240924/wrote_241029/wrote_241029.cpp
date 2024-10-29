// wrote_241029.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}


// 
// 값형...메모리는 만들어져 있지만 초기화 되어 있는지는 알 수 없다.
// 
// WindowImage는 랩핑 클래스, Create()로 호출해서 HDC가 만들어져야 의미가 있다.
// 
// 
// (화면 크기가 바뀌면 엄청나게 느려지는겜? 백버퍼를 전체화면에 맞춘 로직으로 짠 경우다.)
// 우리는 창 크기를 정하고 버퍼는 그걸 따라간다.
// if (WindowSize != )
// 
// float은 비교가 매우 위험하다.
// bool CompareToInt 소수점을 버리고 비교하거나 
// bool Compare (,float _limit = 0.0f) 제한을 둬서 비교
// 
// const가 붙은 함수, const가 붙은 함수만 호출 가능하다.
// 
// HBITMAP
// 
// UEngineImage, ptr로 넣어줄 시 null일 경우 터지게.
// 
// GetObject() 정보를 얻어오는 함수
// 
// FVector2D WindowSize 
// 
// 좋은 엔진은 줄줄이 사탕모양으로 만들지 X
// 오히려 랩핑을 해서 사용자가 엔진 근본에서 멀어지게 만든다.
// 
// BackBuffer -> CopyTo(windowImage)로 결정!
// 
// 
// class FTransform       이미지 크기와 위치를 정할 수 있는 클래스
// {                      일일이 값으로 정하기 힘드니까
// }
// 
// WindowImage의 가운데에 놓고 크기를 맞추는 방식으로 간다.
// 
// 
// BitBlt...SRCCOPY 덮어서 그리는 옵션으로
// 
// DoubleBuffering에 ScreenClear()를 만든다.
// 화면 크기만한 직사각형을 만든다. 지우는 것 같이...
// Render를 시작할 때 그리면 화면이 깨끗하게 보인다. 

// 플레이 도중 윈도우 창 사이즈를 조절하는 기능은 안 만들었다. 
//

// 자주 하는 실수
// void APlayer::BeginPlay()
// {
// GetWorld() -> SpawnActor<APlayer>(); 무한 루프
// }
// 자기가 자기 자신을 만들지 않는다.
// 잘못하면 stack overflow 발생함
//

// 이미지 로드할 때 디렉토리로 간다.
// 
// (EngineBase) EngineDirectory
// GetAllFile();
// 리소스 폴더를 한번 정해준 뒤 Dir.SetPath();
// 선택한 확장자의 파일들만 가져온다. GetAllFile()
// 그리고 이 파일들을 벡터에 담는다. 
// std::vector<UEngineFile> AllFile = Dir.GetAllFile("*.bmp", "")
// 
// 최신 std 기능?!??!
// std::
//

//098_StdPath
// 
// 파일... 경로를 가진다. 
// 경로에서 파일명만 뽑아낸다?
// 
// 옛날에는 파일명을 직접 찾아서 만들었다. (path.rfind()  뒤에서부터 찾는다.)
// 
// 지금은 std filesystem을 사용한다.
// 파일 경로를 관리하는 기능들로 구성되어 있다.
// 경로 제어, 파일 삭제, 디렉토리 만들기 등등...
// 
// 부모 경로(상위 경로)도 알 수 있다. 

// UEngineFile: public UEnginePath
// 
// 파일에 관련된 기능을 제공하는 것도 OS
// 
// 자식 클래스 생성자는 부모 클래스 생성자를 호출한다.
// 이를 명시적으로 표현하는 문법... 생성 체인
// 
// !문제점!
// Debug와 Release의 파일 경로가 다르다.
// Resource를 어디에 둬야 할까?
// 
// bool MoveParentToDirectory();
// 어떤 파일의 부모 경로(파일)를 탐색한다.
// 그리고 원하는 디렉토리가 나올 때까지 무한반복하는 함수
// 실패할 경우를 대비해서 DummyPath에 기존의 경로를 저장해 둔다.
// while(){현재 경로는 CurPath, append(), 현재 경로에 원하는 파일이 있나? 있다면 break}
// 실패하면 false return.
// (UEnginePath delete 해제했다.)
// 
// 상대 경로의 핵심...어디서 실행됐는지는 중요하지 않다, 어디서든 똑같이 실행되어야 한다.
// (경로 직접 입력 금물)
// 
// directory를 vector 선언, iterator 사용한다. 
// _At_end()
// 
// IsFile 파일인가?
// IsDirectory 디렉토리가 존재하나?
// 
// namespace
// OutPutString(); VS출력창에 보이게 하는 함수
// (헤더에 함수 선언하지 말고...)
// 
// 재귀함수 방식으로
// GetAllFileRecursive()
// (하위 폴더를 찾고 싶지 않다면 bool _IsRecursive를 false로)
// 
// 확장자 구분 기능은....다음에
//

//리소스 파일 이름 정하는거 잊지 말기



