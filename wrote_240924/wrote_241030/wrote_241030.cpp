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

//png와 bmp를 로드하는 방식은 다르다.
//bmp는 쉽게 로딩되지만 png는 변환을 거친 뒤 로딩된다.
// jpg는 alpha값이 없다.(투명이 불가능) R, G, B값만 있다.
// 
// !주의!
// 언리얼은 무조건 파일을 대문자로 변경해서 가지고 있다. (실수에 대비해서...)
// 대소문자 구분 안하기 때문에 한 파일에 이름의 스펠링이 같은 파일이 있어선 안 된다.
// 
// (EngineBase) UEngineString
// toupper
// 소문자를 대문자로 바꾸는 함수
// for문은 일부러 만들었다. (아마 전체를 확인하는 함수 있을것...)
//
// 아주 고릿적부터 있었던...window기본 이미지 라이브러리 2가지...(API 이후 안 쓴다)
// 
// png를 로드해서 gdiplus를 그대로 사용하면 프레임이 크게 떨어진다. (그래픽카드와 다렉이 필요함)
// 따라서 로딩만 gdiplus로, 그 이후는
// 
// 멀티바이트를 쓰기로 했는데...wchar_t 등장.
// 인코딩을 하자.
// AnsiToUnicode 
// (이것도 OS가 제공해준다. 국가코드를 OS가 관리하니까.)
// MultiByteToWideChar() 국가코드를 기반으로 멀티를 와이드로.
// 
// 멀티바이트 n바이트를 와이드로 변환하면...몇 바이트인지 알 수 없다.
// 바꾸려면 몇 바이트가 필요한 지 알아내주는 함수도 필요하지만 위 함수가 다 한다.
// 
// (vector 정해지지 않은 사이즈를 쓰는건 좋지 않다.)
// (마지막 2개의 인자)nullptr, 버퍼길이 0으로 정하면 변환된 크기가 얼마인지 알려주는 함수가 된다.
// 
// 크기를 알아내고 다시 변환시킨다.
//
// 원본 훼손하지 않고 복사본으로 bitmap을 생성한다.
// Gdiplus::Bitmap* pBitmap = reinterpre
// 
// 
// png의 alpha값을 어떻게 처리할까? color (0, 0, 0, 0)
//                                       검은색으로 처리했다.
// &hBitMap 넣어준 포인터에 결과를 넣어준다.
// Gdiplus::Status가 Ok가 아니면 문제가 생긴거니 터뜨리기.
// 
// 그리고 Gdiplus는 leak 발생하니 delete해줘야 함.
// delete pBitMap;
// delete pImage;
 
// NewBitmap이 null이면 터진다.
// 
// 윈도우가 만들어준 메모리...leak이 발생하진 않겠지만 명시적으로 써주겠다.
// 
// 릴리즈 순서는 만들어진 순서의 역순으로.
// 
// UImageManager, new UEngineWinImage 했으니 소멸자에 Delete
//
// 이미지를 어떤 크기로 스프라이트를 만들건가?
// 자르는 위치의 기준을 왼쪽 위로 (에디터처럼 중심으로 하기엔 힘들다)
// 0,0에서 이미지 전체 크기
// Trans.Location = {(0,0)}
// Trans.Scale
// 
// 
// FVector 2D GetImageScale()
// 컴파일러 <[똑같은 생성자가 2개인데 long이 없으니 int로 할까? float으로 할까?]
// float으로 하라고 static_cast로 명시적으로 써준다.
// 
// 인터페이스를 전담하는 클래스는 나중에 만들고 일단 이미지를 띄워보자.
// 
// 모든 actor는 이미지를 셋팅해야하게 만들어 놓겠다.
// 
// AActor에서 순환참조가 의심되서 UEnginesSprite 헤더 지우고 전방 선언했다.
// 

//CurPAth.root_path 무한루프 해결

// 로드할 때 대문자로 로드됨
// 
// 방어코드는 꼼꼼하게 해도 부족하다
// 철저하게!
// 
// USpriteData GetSpriteData() 
// 그리 크지 않으니 값으로 return.
// 
// CurData.Image
// CurData.Transform 
// 이 둘을 backbuffer에 그린다.
// 
// 옛날 그래픽스 라이브러리들은 색깔 기반으로 지운다.
// 그래서 가장 잘 안쓰는 마젠타를 ignore color로 사용했다.
// 
// CurData.Image -> CopyToBit(BackBufferImage, Tranform)
//                             이 이미지를    이 위치에 복사
// 
// bit블릿은 렌더가 제일 빠르지만 크기 조절이 안된다.
// TransparentBlt
// 색깔 제외도 되고 이미지의 일부를 처리할 수 있다.
// 
// (EngineBase) Math에 class UColor를 만든다. 
// 
// CopyDC를 
//

// (png 이미지 편집은 ppt 확인하고)
// 
// 텍스처가 다 로딩되면 자르는 작업을 한다.
// void CuttingSprite (std::string_view _KeyName, )
// 
// 편집된 이미지의 간격등 사이즈를 정확하게 알아야 한다.
// UImageManager
// 
// ClearSpriteData()
// 기존의 sprite를 지우는 함수
// 
// Sprite -> ClearSpriteData
// int X = 
// int Y = 
// 
// 이미지 사이즈가 딱 맞지 않으면 터진다.
//



