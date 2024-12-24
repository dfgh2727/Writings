// wrote_241224.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// (어제에 이어서...)
// dll 프로세스 메모리 공유 문제
// 
// dll의 경우 파일 각자가 static을 인식해서 복붙한다.
// 즉 static인 값이 여러개가 생긴다.
// (호출 스택에서 호출의 주체를 확인해보자.)
// 
// --해결 방법--
// 한 곳에서만 생성된 static을 사용하게 만든다. 
// 
// (1) 전처리 문을 사용해 dll 간에 메모리 쉐어가 가능하게 만든다.
// -> 문제는 stdl은 내부에 멤버변수를 가진 것과 같아서 사용 불가. 
//    (자료구조 등을 사용할 수 없다.)
// 
// (2) (1)을 해결하기 위해 라이브러리를 사용한다.
// 
// 템플릿은 전부 헤더에 구현하니 include 되면 데이터 영역에 생성된다.
// 템플릿을 전부 제거하고 resource관리 함수들은 전부 core에서만 사용되게 한다.
// 
// resmap이 여러개 생기는 것을 방지하기 위해
// 여러개의 map이 아니라 (core에 만들어진) 하나의 map안에 리소스들을 넣고 관리하게 만든다.
// (버텍스, 인덱스, 레스터라이저 등을 하나의 map에 넣고 관리)
// (new 할당을 core안에서 이루어지게 만든다...)
// 
// find로 UEngineResource를 return 그리고 dynamic cast 한다.
// 

// RTTI (Runtime Type Information)
// ->104_TypeID 참고 

// 리소스 전체가 아닌 일부를 선택적으로 렌더하고 싶다면
// UV 값을 바꿔서 범위를 선택할 수 있다.
// 
// 그리고 Unmap, Map을 통해 런타임 중에 수정할 수 있다.
// (가능하면 피하는게 좋다.)
// 
// (Renderer.cpp)
// 같은 이미지를 사용하되 서로 다른 부분을 렌더하고 싶다?
// 상수 버퍼(Sprite Const Buffer)를 이용해 값을 변경시켜서 렌더한다.
// !인덱스가 겹치면 안 된다!
// 
// cbuffer FSpriteData : register()
// {
// }
// void SetSpriteData(float4 _CuttingPos, float4 _CuttingSize);

// Parsing (파싱)
//
// 문자열이 일정 규칙으로 구성되어 있다는 것을 파악하고 분해해서 의미를 부여하는 것
// 파싱을 기반으로 하는 언어를 structured 언어라고 한다. 대표적인 예로 xml, json이 있다.
// 텍스트 파일 전체를 읽어서 분해해서 정보를 파악한다.
// 
// Unity의 meta 파일을 읽는 기능을 만들었다.
// 
// 잘린 스프라이트의 이름과 크기, 위치를 가져와야 한다.
// 키워드를 찾아서 그것을 기준으로 원하는 정보를 가져온다.

//imgui 적용
//
// github를 찾아서 description에 사용법이 있으니 읽어보자.
// 
// 옵션을 master가 아닌 docking으로 하면 창이 합쳐진다.
// 
// UEngineGUI
// ImGUI 관리 클래스
// 
// 현재 쓰고 있는 hwnd와 Device, Context로 내용을 수정해준다.
// ImplWin32_ShutDown(), DestroyContext() 등으로 leak이 발생하지 않게 만듦
// (impl 확장이라는 의미)
// 
// ImGUI...새로운 윈도우 창이 생김
// static std::function<bool(어쩌구)> CustomProc;
// 윈도우 창에 메시지가 전달될 때 원하는 기능을 실행할 수 있게 만들자. 
// CustomProc을 넘겨받아 사용할 수 있게 만들었다.
// 
// ImGUI도 다렉을 이용해 렌더된다... 즉 렌더 파이프 라인을 통해 렌더된다.
// 현재 만든 DX 프로젝트에서 실행중인 파이프 라인 단계와 별개로 다른 단계를 실행할 수 있다.




