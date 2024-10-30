// wrote_241030.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// (API)
// 모든걸 backbuffer에 그리고 딱 한번 backbuffer를 올린다.
// ScreenClear를 안하면 검은 잔상이 남는다.
// 
// 디렉토리를 왜 만들었을까
// 과거에는 std string으로 일일이 경로를 확인하고 파일명을 직접 추출했었다.
// std filesystem은 최신 기술... 안 쓰는 곳도 있다.
// 디렉토리나 파일 관련 함수들을 모두 모아놓은 것
// std의 장점... C++이 빌드되는 곳에서는 모두 다 동일하게 돌아간다.
// 
// GetAllFile에 확장자 구분하는 기능은 안 만듦. 나중에 할 거임...
// 
// 전체 리소스, 레벨 리소스를 구분하는걸 추천한다.
// 
// 상대경로로 file을 찾아낸다는걸 기억해라!
// 빌드된 결과물(bin과 resource, exe)만 보낼 때 주의해야 한다.
// 전체 통째로 보내면 안 됨;;
// 
// 이미지 리소스를 (아틀라스가 아닌)분리된 이미지로 가지고 있다면 LoadDirectory를 써야 한다.
// 
// GetExtension() 확장자를 얻어내는 함수 
// 
// 애니메이션이란?
// 여러개의 프레임이 돌아가는 거다.
// UEngineWinImage*를 잘라서 써야한다.
// 
// 이미지를 잘라서 쓰는걸 sprite라고 한다.
// (EngineCore) UEngineSprite
// 따라서 ImageManager는 Image가 아닌 Sprite를 가지게 된다.
// 그리고 자르는 코드는 직접 입력해야 한다. 따라서 칸이 정확하게 나뉘어진 이미지를 쓰는 것이 편하다.
// 
// UEngineSprite
// private:
// std::vector<SpriteData>
// 
// FTransform 자주 쓰니까 Ref로 쓰자. const FTranform&
// 
// 이미지를 잘랐는데 크기가 0이다? 터뜨린다.
// 
// 이름을 붙이는 기능은 EngineCore에 어울리지만, 재탕하기 쉽게 EngineBase에 둔다.  
// UObject
// 자식들의 소멸자가 호출되지 않는 상황을 막기 위해 소멸자 virtual 처리.
// 
// AActor
//